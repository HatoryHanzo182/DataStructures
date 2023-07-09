#pragma once
#include "Header.h"

namespace BinaryTreeDemo
{
	#pragma region Node struct.
	template<typename Key, typename Value>
	struct Node
	{
		Node<Key, Value>* _parent;
		Node<Key, Value>* _left;
		Node<Key, Value>* _right;
		Key _key;
		Value _value;

		Node() : _parent(nullptr), _left(nullptr), _right(nullptr), _value() {}

		bool IsLeft();
		bool IsRight();
		bool HasTwoChildren();
	};
	#pragma endregion

	template<typename Key, typename Value>
	class BinTree
	{
	private:
		Node<Key, Value>* _root;
		size_t _size;

		Node<Key, Value>* MinNode(Node<Key, Value>*) const;
		Node<Key, Value>* SearchNode(Key) const;
		void Clear(Node<Key, Value>*);
	public:
		BinTree();

		void Add(Key, Value);
		void Remove(Key);
		void Clear();
		size_t Size() const;
	
		const Value& operator[](Key key) const;
		
		~BinTree();
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