#include <cstdint>
#include <cassert>
#include <vector>
#include <memory>
#include <optional>

/*
 * The van Emde Boas tree implementation.
 *
 * Operation complexity:
 * - insert: O(log(W))
 * - erase: O(log(W))
 * - contains: O(log(W))
 * - get successor: O(log(W))
 * - get precedessor: O(log(W))
 * - get min: O(1)
 * - get max: O(1)
 *
 * @param W power of max value, 32 for uint32.
 */
template<unsigned W>
class VebTree {
	using Child = VebTree<W / 2>;

	/* Min value, not contained in m_children. */
	std::optional<uint64_t> m_min;
	/* Max value, not contained in m_children. */
	std::optional<uint64_t> m_max;
	/* Up to 2 ^ (W / 2) subtrees. */
	std::vector<std::unique_ptr<Child>> m_children;
	/* Auxiliary tree. */
	std::unique_ptr<Child> m_aux;

public:
	VebTree()
	: m_children(1ULL << (W / 2))
	{
		assert(W >= 1);
		if (W > 1)
			m_aux = std::make_unique<Child>();
	}

	bool
	empty()
	{
		return !m_min;
	}

	bool
	contains(uint64_t value)
	{
		assert(value < (1ULL << W));

		if (m_min && *m_min == value)
			return true;
		if (m_max && *m_max == value)
			return true;

		/* W == 1 tree never has children. */
		uint64_t h = high(value);
		if (!m_children[h])
			return false;

		uint64_t l = low(value);
		return m_children[h]->contains(l);
	}

	void
	insert(uint64_t value)
	{
		assert(value < (1ULL << W));

		if (!m_min) {
			/* The tree is empty. */
			m_min = value;
			m_max = value;
			return;
		}

		/* The element exists (min or max). */
		if (value == *m_min || value == *m_max)
			return;

		if (value < *m_min) {
			uint64_t old_min = *m_min;
			m_min = value;

			/* This is the second element inserted. */
			if (old_min == *m_max)
				return;

			/* Insert the old min into a corresponding child. */
			value = old_min;
		}

		if (value > *m_max) {
			uint64_t old_max = *m_max;
			*m_max = value;

			/* This is the second element inserted. */
			if (old_max == *m_min)
				return;

			/* Insert the old max into a corresponding child. */
			value = old_max;
		}

		/* If W == 1, all tree values are in m_min and m_max. */
		assert(W > 1);

		uint64_t l = low(value);
		uint64_t h = high(value);

		/* Create a corresponding child if it does not exist. */
		if (!m_children[h]) {
			m_children[h] = std::make_unique<Child>();

			/* Mark that the child is not empty anymore. */
			m_aux->insert(h);
		}

		/* Insert the value into the corresponding child. */
		m_children[h]->insert(l);
	}

	bool
	erase(uint64_t value)
	{
		assert(value < (1ULL << W));

		/* The tree is empty. */
		if (!m_min)
			return false;

		/* The tree only contains the element we delete. */
		if (*m_min == *m_max && value == *m_min) {
			m_min.reset();
			m_max.reset();
			return true;
		}

		/* Remove the min element. */
		if (value == *m_min) {
			/* There's no children. */
			if (W == 1 || m_aux->empty()) {
				*m_min = *m_max;
				return true;
			}

			/* Get new min element from children. */
			uint64_t h = *m_aux->min();
			assert(m_children[h] != nullptr);
			*m_min = concat(*m_children[h]->min(), h);

			/* Remove it from children. */
			value = *m_min;
		}

		/* Remove the max element. */
		if (value == *m_max) {
			/* There's no children. */
			if (W == 1 || m_aux->empty()) {
				*m_max = *m_min;
				return true;
			}

			/* Get new max element from children. */
			uint64_t h = *m_aux->max();
			assert(m_children[h] != nullptr);
			*m_max = concat(*m_children[h]->max(), h);

			/* Remove it from children. */
			value = *m_max;
		}

		/* W == 1 tree never has children. */
		uint64_t h = high(value);
		if (!m_children[h])
			return false;

		uint64_t l = low(value);
		bool result = m_children[h]->erase(l);

		/* Mark the chlid is empty if required. */
		if (m_children[h]->empty()) {
			m_children[h].reset();
			m_aux->erase(h);
		}
		return result;
	}

	std::optional<uint64_t>
	successor(uint64_t value)
	{
		assert(value < (1ULL << W));

		if (!m_min || value >= *m_max)
			return {};

		if (value < *m_min)
			return *m_min;

		if (value == *m_min) {
			/* There's no chlidren - return max. */
			if (W == 1 || m_aux->empty())
				return *m_max;

			/* Return min of children. */
			uint64_t h = *m_aux->min();
			assert(m_children[h] != nullptr);
			return concat(*m_children[h]->min(), h);
		}

		/* Find the successor in the corresponding child (if any). */
		uint64_t l = low(value);
		uint64_t h = high(value);
		if (m_children[h] != nullptr) {
			std::optional<uint64_t> s = m_children[h]->successor(l);
			if (s)
				return concat(*s, h);
		}

		/* Get the successor from the succeeding child (if any). */
		std::optional<uint64_t> sc = m_aux->successor(h);
		if (sc) {
			uint64_t h = *sc;
			assert(m_children[h] != nullptr);
			return concat(*m_children[h]->min(), h);
		}

		/* Not in the corresponding nor next child, so it's max. */
		return *m_max;
	}

	std::optional<uint64_t>
	predecessor(uint64_t value)
	{
		assert(value < (1ULL << W));

		if (!m_min || value <= *m_min)
			return {};

		if (value > *m_max)
			return *m_max;

		if (value == *m_max) {
			/* There's no chlidren - return min. */
			if (W == 1 || m_aux->empty())
				return *m_min;

			/* Return max of children. */
			uint64_t h = *m_aux->max();
			assert(m_children[h] != nullptr);
			return concat(*m_children[h]->max(), h);
		}

		/* Find the predecessor in the corresponding child (if any). */
		uint64_t l = low(value);
		uint64_t h = high(value);
		if (m_children[h] != nullptr) {
			std::optional<uint64_t> s =
				m_children[h]->predecessor(l);
			if (s)
				return concat(*s, h);
		}

		/* Get the predecessor from the preceding child (if any). */
		std::optional<uint64_t> sc = m_aux->predecessor(h);
		if (sc) {
			uint64_t h = *sc;
			assert(m_children[h] != nullptr);
			return concat(*m_children[h]->max(), h);
		}

		/* Not in the corresponding nor preceding child, so it's min. */
		return *m_min;
	}

	std::optional<uint64_t>
	min()
	{
		return m_min;
	}

	std::optional<uint64_t>
	max()
	{
		return m_max;
	}

private:
	uint64_t
	high(uint64_t value)
	{
		return value >> (W / 2);
	}

	uint64_t
	low(uint64_t value)
	{
		return value & ((1ULL << (W / 2)) - 1);
	}

	uint64_t
	concat(uint64_t l, uint64_t h)
	{
		return l | (h << (W / 2));
	}
};

template<>
class VebTree<4>
{
	uint64_t m_mask;

public:
	VebTree()
	: m_mask(0)
	{}

	bool
	empty()
	{
		return m_mask == 0;
	}

	bool
	contains(uint64_t value)
	{
		assert(value < (1ULL << 4));
		return m_mask & (1ULL << value);
	}

	void
	insert(uint64_t value)
	{
		assert(value < (1ULL << 4));
		m_mask |= (1ULL << value);
	}

	bool
	erase(uint64_t value)
	{
		assert(value < (1ULL << 4));
		bool result = contains(value);
		m_mask &= ~(1ULL << value);
		assert(!contains(value));
		return result;
	}

	std::optional<uint64_t>
	successor(uint64_t value)
	{
		assert(value < (1ULL << 4));
		uint64_t mask_after = m_mask & ~((1ULL << (value + 1)) - 1);
		if (mask_after == 0)
			return {};
		return __builtin_ffs(mask_after) - 1;
	}

	std::optional<uint64_t>
	predecessor(uint64_t value)
	{
		assert(value < (1ULL << 4));
		uint64_t mask_prior = m_mask & ((1ULL << value) - 1);
		if (mask_prior == 0)
			return {};
		return ((1ULL << 4) - 1) - (__builtin_clzl(mask_prior) - (64 - (1ULL << 4)));
	}

	std::optional<uint64_t>
	min()
	{
		if (m_mask == 0)
			return {};
		return __builtin_ffs(m_mask) - 1;
	}

	std::optional<uint64_t>
	max()
	{
		if (m_mask == 0)
			return {};
		return ((1ULL << 4) - 1) - (__builtin_clzl(m_mask) - (64 - (1ULL << 4)));
	}
};
