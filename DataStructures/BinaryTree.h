#pragma once
#include "Header.h"

//
//██████╗░██╗███╗░░██╗░█████╗░██████╗░██╗░░░██╗  ████████╗██████╗░███████╗███████╗
//██╔══██╗██║████╗░██║██╔══██╗██╔══██╗╚██╗░██╔╝  ╚══██╔══╝██╔══██╗██╔════╝██╔════╝
//██████╦╝██║██╔██╗██║███████║██████╔╝░╚████╔╝░  ░░░██║░░░██████╔╝█████╗░░█████╗░░
//██╔══██╗██║██║╚████║██╔══██║██╔══██╗░░╚██╔╝░░  ░░░██║░░░██╔══██╗██╔══╝░░██╔══╝░░
//██████╦╝██║██║░╚███║██║░░██║██║░░██║░░░██║░░░  ░░░██║░░░██║░░██║███████╗███████╗
//╚═════╝░╚═╝╚═╝░░╚══╝╚═╝░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░  ░░░╚═╝░░░╚═╝░░╚═╝╚══════╝╚══════╝
//
// A binary tree is a hierarchical data structure consisting of nodes, where each node has a maximum of two children: left and right. 
// The nodes are connected to each other by directed edges, and each node has a parent node, except for the root node, which has no parent.
//
// The main characteristics of a binary tree :
// Root: This is the vertex that is the starting point of the tree.
// Nodes : Each node can have at most two children(left and right).
// Leaves : Leaves are nodes that have no children.
// Descendants : Nodes directly below another node are called its children.
// Parent : The node immediately preceding another node is called its parent.
// Path : A path is a sequence of nodes starting at the root node and ending at a specific node.
// Height : The height of a binary tree is the length of the longest path from the root node to any of its leaves.
// 
// Binary trees are widely used in computer science and have various variants and applications.They provide efficient access,
// insertion, and deletion of elements in an ordered structure.Binary trees are also the basis for other data structures
// such as binary heaps, AVL trees, and red - black trees.
//
//                 +---+
//                 | 4 |
//                 +---+
//                /     \
//           +---+       +---+
// 	     | 2 |       | 7 |
// 	     +---+       +---+
//                      /     \
//                 +---+       +---+
// 	           | 5 |       | 9 |
// 	           +---+       +---+
// 


namespace BinaryTreeDemo
{
	#pragma region Node struct.
	template<typename Key, typename Value>
	struct Node
	{
		Node<Key, Value>* _parent;  // A pointer to the parent node.
		Node<Key, Value>* _left;  // A pointer to the left child node.
		Node<Key, Value>* _right;  // A pointer to the right child node.
		Key _key;  // The key associated with the node.
		Value _value;  // The value associated with the node.

		explicit Node() : _parent(nullptr), _left(nullptr), _right(nullptr), _value() {}  // default constructor, initializes _parent, _left, and _right pointers to nullptr, 
																				         // and _value to the default value for the Value type.
		bool IsLeft();  // Returns true if the node is a left child.
		bool IsRight();  // Returns true if the node is a right child.
		bool HasTwoChildren();  // Returns true if the node has both left and right children.
	};
	#pragma endregion

	template<typename Key, typename Value>
	class BinTree
	{
	private:
		Node<Key, Value>* _root;  // A pointer to the root node of the binary tree. It represents the starting point of the tree and provides access to all other nodes.
		size_t _size;  //  A variable that stores the number of nodes in the binary tree. It keeps track of the size or the total count of elements in the tree.

		Node<Key, Value>* MinNode(Node<Key, Value>*) const;  // Returns a pointer to the node with the minimum key in the subtree starting from the given node.
		Node<Key, Value>* SearchNode(Key) const;  // Searches for a node with the specified key in the tree and returns its pointer if found.
		void Clear(Node<Key, Value>*);  // Clears the tree, freeing the memory.
	public:
		explicit BinTree();  // Default constructor, initializes _root pointer to nullptr and _size to the default value for size_t type.

		void Add(Key, Value);  // Adds a new node with the specified key and value to the tree.
		void Remove(Key);  // Removes the node with the specified key from the tree.
		void Clear();  // Clears the tree, freeing the memory.
		size_t Size() const;  // Returns the size of the tree.
	
		const Value& operator[](Key key) const;  // Returns the value associated with the specified key in the tree.
		
		~BinTree();  // Destructor, calls Clear() to free the memory.
	};

	#pragma region Implementation Node.
	template<typename Key, typename Value>
	inline bool Node<Key, Value>::IsLeft() { return _left == nullptr && _right == nullptr; }
	
	template<typename Key, typename Value>
	inline bool Node<Key, Value>::IsRight() { return _left != nullptr && _right != nullptr || _left == nullptr && _right != nullptr; }

	template<typename Key, typename Value>
	inline bool Node<Key, Value>::HasTwoChildren() { return _left != nullptr && _right != nullptr; }
	#pragma endregion

	#pragma region Implementation.
	template<typename Key, typename Value>
	inline BinTree<Key, Value>::BinTree()
	{
		this->_root = nullptr;
		this->_size = size_t();
	}

	template<typename Key, typename Value>
	inline Node<Key, Value>* BinaryTreeDemo::BinTree<Key, Value>::MinNode(Node<Key, Value>* node) const
	{
		if (node == nullptr)
			return nullptr;

		Node<Key, Value>* min_node = node;

		while (min_node->_left != nullptr)
			min_node = min_node->_left;

		return min_node;
	}

	template<typename Key, typename Value>
	inline Node<Key, Value>* BinTree<Key, Value>::SearchNode(Key key) const
	{
		Node<Key, Value>* cursor = _root;

		while (cursor != nullptr)
		{
			if (cursor->_key == key)
				return cursor;
			else if (key < cursor->_key)
				cursor = cursor->_left;
			else if (key > cursor->_key)
				cursor = cursor->_right;
		}
		return nullptr;
	}

	template<typename Key, typename Value>
	inline void BinTree<Key, Value>::Clear(Node<Key, Value>* root)
	{
		if (root != nullptr)
		{
			Clear(root->_left);
			Clear(root->_right);

			delete root;
			--_size;
		}
	}

	template<typename Key, typename Value>
	inline void BinTree<Key, Value>::Add(Key key, Value value)
	{
		Node<Key, Value>* cmd = new Node<Key, Value>();

		cmd->_key = key;
		cmd->_value = value;

		if (_root == nullptr)
			_root = cmd;
		else
		{
			Node<Key, Value>* cursor = _root;
			Node<Key, Value>* current = _root;

			while (cursor != nullptr)
			{
				current = cursor;
				
				if (key < cursor->_key)
					cursor = cursor->_left;
				else
					cursor = cursor->_right;
			}
			cmd->_parent = current;
			
			if (key < current->_key)
				current->_left = cmd;
			else
				current->_right = cmd;
		}
		++_size;
	}

	template<typename Key, typename Value>
	inline void BinaryTreeDemo::BinTree<Key, Value>::Remove(Key key)
	{
		Node<Key, Value>* cmd = SearchNode(key);

		if (cmd == nullptr)
			return;

		if (cmd->HasTwoChildren())
		{
			Node<Key, Value>* successor = MinNode(cmd->_right);

			cmd->_key = successor->_key;
			cmd->_value = successor->_value;
			cmd = successor;
		}

		Node<Key, Value>* child = (cmd->_left != nullptr) ? cmd->_left : cmd->_right;
		Node<Key, Value>* parent = cmd->_parent;

		if (child != nullptr)
			child->_parent = parent;

		if (parent == nullptr)
			_root = child;
		else if (parent->_left == cmd)
			parent->_left = child;
		else
			parent->_right = child;

		delete cmd;
		_size--;
	}

	template<typename Key, typename Value>
	inline void BinaryTreeDemo::BinTree<Key, Value>::Clear() 
	{ 
		Clear(_root);

		_root = nullptr;
	}

	template<typename Key, typename Value>
	inline size_t BinaryTreeDemo::BinTree<Key, Value>::Size() const { return _size; }

	template<typename Key, typename Value>
	inline const Value& BinaryTreeDemo::BinTree<Key, Value>::operator[](Key key) const
	{
		Node<Key, Value>* cmd = SearchNode(key);

		return cmd->_value;
	}

	template<typename Key, typename Value>
	inline BinaryTreeDemo::BinTree<Key, Value>::~BinTree() { Clear(_root); }
	#pragma endregion
}
