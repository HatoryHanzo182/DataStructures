#pragma once
#include "Header.h"

namespace BinaryTreeDemo
{
	#pragma region Node struct.
	template<typename Key, typename Value>
	struct Node
	{
		Node* _parent;
		Node* _left;
		Node* _right;
		Key _key;
		Value _value;

		Node() = default;

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

		//Node* MinNode(Node*) const;
		Node<Key, Value>* SearchNode(Key) const;
	public:
		BinTree();

		void Add(Key, Value);
		//void Remove(Key);
		//void Cleer();
		//
		//const Value& operator[](Key key) const;
		//
		//~BinTree();
	};

	#pragma region Implementation Node.
	template<typename Key, typename Value>
	inline bool Node<Key, Value>::IsLeft() { return _left == nullptr && _right == nullptr; }
	
	template<typename Key, typename Value>
	inline bool Node<Key, Value>::IsRight() { return _left != nullptr && _right != nullptr || _left == nullptr && _right != nullptr; }

	template<typename Key, typename Value>
	inline bool Node<Key, Value>::HasTwoChildren() { _left != nullptr && _right != nullptr; }
	#pragma endregion

	#pragma region Implementation.
	template<typename Key, typename Value>
	inline BinTree<Key, Value>::BinTree()
	{
		this->_root = nullptr;
		this->_size = size_t();
	}

	template<typename Key, typename Value>
	inline Node<Key, Value>* BinTree<Key, Value>::SearchNode(Key key) const
	{

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
	#pragma endregion
}