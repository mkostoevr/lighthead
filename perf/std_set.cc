#include <random>
#include <set>

#include <benchmark/benchmark.h>

#include "perf.hh"

template<typename KeyGen>
static void
std_set_find(benchmark::State &state, size_t count, KeyGen kg)
{
	std::set<uint32_t> s;
	for (size_t i = 0; i < count; i++)
		s.insert(i);
	for (auto _ : state)
		benchmark::DoNotOptimize(s.find(kg()));
}

generate_benchmark_keys_size_iterations(std_set_find, 1000000);

template<typename KeyGen>
static void
std_set_lower_bound(benchmark::State &state, size_t count, KeyGen kg)
{
	std::set<uint32_t> s;
	for (size_t i = 0; i < count; i++)
		s.insert(i);
	for (auto _ : state)
		benchmark::DoNotOptimize(s.lower_bound(kg()));
}

generate_benchmark_keys_size_iterations(std_set_lower_bound, 1000000);

template<typename KeyGen>
static void
std_set_upper_bound(benchmark::State &state, size_t count, KeyGen kg)
{
	std::set<uint32_t> s;
	for (size_t i = 0; i < count; i++)
		s.insert(i);
	for (auto _ : state)
		benchmark::DoNotOptimize(s.upper_bound(kg()));
}

generate_benchmark_keys_size_iterations(std_set_upper_bound, 1000000);

template<typename KeyGen>
static void
std_set_insert(benchmark::State &state, size_t count, KeyGen kg)
{
	std::set<uint32_t> s;
	for (auto _ : state)
		s.insert(kg());
}

generate_benchmark_keys_size_iterations(std_set_insert, 1000000);

BENCHMARK_MAIN();
