#include <cstdint>

#include <memory>

template<typename T, size_t MAX_COUNT_IN_INNER = 20,
	 size_t MAX_COUNT_IN_LEAF = 40, size_t MAX_HEIGHT = 16>
class BpsTree {
	struct Block {
		enum Type {
			INNER,
			LEAF
		} type;
		size_t size;

		Block(enum Type type)
		: type(type)
		, size(0)
		{}
	};

	struct Inner: Block {
		T elements[MAX_COUNT_IN_INNER - 1];
		std::unique_ptr<Block> children[MAX_COUNT_IN_INNER];

		Inner()
		: Block(Block::Type::INNER)
		{}
	};

	struct Leaf: Block {
		T elements[MAX_COUNT_IN_LEAF];

		Leaf()
		: Block(Block::Type::LEAF)
		{}
	};

	struct Path {
		struct Parent {
			Inner *inner;
			size_t insertion_point;
			size_t position_in_parent;
		} parents[MAX_HEIGHT];
		Leaf *leaf;
		size_t insertion_point;
		size_t position_in_parent;
	};

private:
	std::unique_ptr<Block> root;
	size_t size;
	size_t height;

public:
	BpsTree()
	: size(0)
	, height(0)
	{}

	void
	insert(T value)
	{
		if (root == nullptr) {
			root = std::make_unique<Leaf>();
			root->elements[root->size++] = value;
			size++;
			height++;
			return;
		}

		Path path = collect_path(value);
	}

private:
	Path
	collect_path(T value)
	{
		Path path = {};
		return path;
	}
};
