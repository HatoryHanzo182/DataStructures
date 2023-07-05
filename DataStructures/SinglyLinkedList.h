#pragma once
#include "Header.h"

namespace SinglyLinkedListDemo
{
	template<typename T>
	class SinglyLinkedList
	{
	private:
		#pragma region Node struct.
		struct Node
		{
		public:
			Node* _pnext;
			T _data;
		public:
			Node();
			Node(const Node*, const T);
		};
	#pragma endregion

		Node<T>* _head;
		size_t _size;
	public:
		SinglyLinkedList();
		SinglyLinkedList(const SinglyLinkedList&);
		//SinglyLinkedList(SinglyLinkedList&&);

		void push_back(const T&);
		//void front_back(const T&);
		//void pop_back(const T&);
		//void pop_front(const T&);
		//void remove_by_index(const size_t);
		//void size();
		//void clear();
		//void swap();

		SinglyLinkedList& operator=(const SinglyLinkedList&);
		//SinglyLinkedList&& operator=(SinglyLinkedList&&);
		//T operator[](size_t);
		//
		//~SinglyLinkedList();
		void Print() const;
	};

	#pragma region Implementation Node.
	template<typename T>
	inline SinglyLinkedList<T>::Node::Node()
	{
		_p_pnext = nullptr;
		_data = T();
	}

	template<typename T>
	inline SinglyLinkedList<T>::Node::Node(const Node* p_pnext, const T data)
	{
		this->_p_pnext = p_pnext;
		this->_data = data;
	}
	#pragma endregion

	template<typename T>
	inline SinglyLinkedList<T>::SinglyLinkedList() 
	{
		this->_head = nullptr;
		this->_size = size_t();
	}

	template<typename T>
	inline SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList& external)
	{
		Node<T>* current = external._head;
		Node<T>* new_node = nullptr;
		Node<T>* prev_node = nullptr;

		while (current != nullptr)
		{	
			new_node = new Node<T>;
			new_node->_data = current->_data;

			if (current = external._head)
				_head = new_node;
			else
				prev_node->_pnext = new_node;

			prev_node = new_node;
			current = current->_pnext
		}
		_size = external._size;
	}

	template<typename T>
	inline void SinglyLinkedList<T>::push_back(const T& meaning)
	{
		Node<T>* tmp = new Node<T>(meaning);

		if (_head == nullptr)
			_head = tmp;
		else
		{
			Node<T>* current = _head;

			while (current->_pnext != nullptr)
				current = current->_pnext;

			current->_pnext = tmp;
		}
		++_size;
	}

	template<typename T>
	inline SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(const SinglyLinkedList& external)
	{
		Node<T>* current = external._head;
		Node<T>* new_node = nullptr;
		Node<T>* prev_node = nullptr;

		while (current != nullptr)
		{
			new_node = new Node<T>;
			new_node->_data = current->_data;

			if (current = external._head)
				_head = new_node;
			else
				prev_node->_pnext = new_node;

			prev_node = new_node;
			current = current->_pnext
		}
		_size = external._size;
	}


	template<typename T>
	inline void SinglyLinkedList<T>::Print() const
	{
		ListItem<TValue>* current = _head;

		while (current != nullptr)
		{
			cout << current->_data << "\t";
			current = current->_pnext;
		}
		cout << endl;
	}
}