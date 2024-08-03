#include <random>

#include <benchmark/benchmark.h>

#include "perf.hh"

#include "../VebTree.hh"

template<typename KeyGen>
static void
vebtree_contains(benchmark::State &state, size_t count, KeyGen kg)
{
	VebTree<32> t;
	for (size_t i = 0; i < count; i++)
		t.insert(i);
	for (auto _ : state)
		benchmark::DoNotOptimize(t.contains(kg()));
}

generate_benchmark_keys_size_iterations(vebtree_contains, 1000000);

template<typename KeyGen>
static void
vebtree_successor(benchmark::State &state, size_t count, KeyGen kg)
{
	VebTree<32> t;
	for (size_t i = 0; i < count; i++)
		t.insert(i);
	for (auto _ : state)
		benchmark::DoNotOptimize(t.successor(kg()));
}

generate_benchmark_keys_size_iterations(vebtree_successor, 1000000);

template<typename KeyGen>
static void
vebtree_predecessor(benchmark::State &state, size_t count, KeyGen kg)
{
	VebTree<32> t;
	for (size_t i = 0; i < count; i++)
		t.insert(i);
	for (auto _ : state)
		benchmark::DoNotOptimize(t.predecessor(kg()));
}

generate_benchmark_keys_size_iterations(vebtree_predecessor, 1000000);

template<typename KeyGen>
static void
vebtree_insert(benchmark::State &state, size_t count, KeyGen kg)
{
	VebTree<32> t;
	for (auto _ : state)
		t.insert(kg());
}

generate_benchmark_keys_size_iterations(vebtree_insert, 1000000);

BENCHMARK_MAIN();
