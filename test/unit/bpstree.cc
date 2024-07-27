#include <cstdio>
#include <cstdlib>
#include <set>

#include "unit.h"

#include <BpsTree.hh>

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

#define test_erase(tree, set, value) do {	\
	test_key(tree, set, value);		\
	set.erase(value);			\
	tree.erase(value);			\
	fail_unless(!tree.contains(value));	\
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

int
main()
{
	BpsTree<uint32_t> tree;
#if 0
	VebTree tree(32);
	std::set<uint32_t> set;
	const size_t count = 100000;

	for (int i = 1; i < count; i++)
		test_insert(tree, set, i * 2);

	fail_unless(!tree.contains(0));
	fail_unless(!tree.contains(1));
	for (int i = 1; i < count; i++) {
		fail_unless(tree.contains(i * 2));
		fail_unless(!tree.contains(i * 2 + 1));
	}

	for (int i = 0; i < count * 2; i++)
		test_successor(tree, set, i);

	for (int i = 0; i < count * 2; i++)
		test_predecessor(tree, set, i);

	for (int i = 0; i < count; i++)
		test_erase(tree, set, i * 2);
#endif
	return 0;
}
