#pragma once

#define generate_benchmark_key_size(func, key, size) static void \
	func##_##key##_size_##size(benchmark::State &state) \
	{ \
		func(state, size, key(size)); \
		state.SetItemsProcessed(size); \
	} \
	BENCHMARK(func##_##key##_size_##size)

#define generate_benchmark_key_size_iterations(func, key, size) \
	generate_benchmark_key_size(func, key, size)->Iterations(size)

#define generate_benchmark_keys_size_iterations(func, size) \
	generate_benchmark_key_size_iterations(func, IncrementingKey, size); \
	generate_benchmark_key_size_iterations(func, RandomKey, size)

/**
 * Value generators to make key-independent benchmarks.
 */

class RandomKey {
	size_t mod;
	std::minstd_rand rng;
public:
	RandomKey(size_t mod) : mod(mod) {}

	size_t
	operator()()
	{
		return rng() % mod;
	}
};

class IncrementingKey {
	size_t end;
	size_t value;
public:
	IncrementingKey(size_t end) : end(end), value(0) {}

	size_t
	operator()()
	{
		size_t result = value++;
		if (value == end)
			value = 0;
		return result;
	}
};
