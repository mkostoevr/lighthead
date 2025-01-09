#include <cstdio>
#include <cstdlib>
#include <set>

#include "unit.h"

#include <VebTree.hh>

#define test_key(tree, set, key) do {			\
	if (set.find(key) != set.end())			\
		fail_unless(tree.contains(key));	\
	else						\
		fail_unless(!tree.contains(key));	\
} while (false)

#define test_insert(tree, set, value) do {	\
	test_key(tree, set, value);		\
	set.insert(value);			\
	tree.insert(value);			\
	fail_unless(tree.contains(value));	\
} while (false)

#define test_erase(tree, set, value) do {		\
	test_key(tree, set, value);			\
	bool existed = set.erase(value);		\
	fail_unless(tree.erase(value) == existed);	\
	fail_unless(!tree.contains(value));		\
} while (false)

#define test_successor(tree, set, value) do {			\
	test_key(tree, set, value);				\
	auto it = set.upper_bound(value);			\
	if (it != set.end()) {					\
		fail_unless(tree.successor(value));		\
		fail_unless(*tree.successor(value) == *it);	\
	} else {						\
		fail_unless(!tree.successor(value));		\
	}							\
} while (false)

#define test_predecessor(tree, set, value) do {			\
	test_key(tree, set, value);				\
	auto it = set.lower_bound(value);			\
	if (--it != set.end()) {				\
		fail_unless(tree.predecessor(value));		\
		fail_unless(*tree.predecessor(value) == *it);	\
	} else {						\
		fail_unless(!tree.predecessor(value));		\
	}							\
} while (false)

template <int W>
void
check_simple(size_t count)
{
	note("W = %d", W);

	VebTree<W> tree;
	std::set<uint32_t> set;

	/* Insert some data. */
	for (int i = 1; i < count; i++)
		test_insert(tree, set, i * 2);

	/* Check if the data is correct. */
	fail_unless(!tree.contains(0));
	fail_unless(!tree.contains(1));
	for (int i = 1; i < count; i++) {
		fail_unless(tree.contains(i * 2));
		fail_unless(!tree.contains(i * 2 + 1));
	}

	/* Check the tree.successor(). */
	for (int i = 0; i < count * 2; i++)
		test_successor(tree, set, i);

	/* Check the tree.predecessor(). */
	for (int i = 0; i < count * 2; i++)
		test_predecessor(tree, set, i);

	/* Check the existing and unexisting data erase. */
	for (int i = 0; i < count * 2; i++)
		test_erase(tree, set, i);

	/* Fill and clear the tree once again. */
	for (int i = 1; i < count; i++)
		test_insert(tree, set, i * 2);
	for (int i = 1; i < count * 2; i++)
		test_erase(tree, set, i);
}

int main() {
	check_simple<4>(8);
	check_simple<32>(100000);
	return 0;
}
