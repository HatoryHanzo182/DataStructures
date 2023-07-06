#pragma once
#include "Header.h"

//
// ░██████╗██╗███╗░░██╗░██████╗░██╗░░░░░██╗░░░██╗  ██╗░░░░░██╗███╗░░██╗██╗░░██╗███████╗██████╗░
// ██╔════╝██║████╗░██║██╔════╝░██║░░░░░╚██╗░██╔╝  ██║░░░░░██║████╗░██║██║░██╔╝██╔════╝██╔══██╗
// ╚█████╗░██║██╔██╗██║██║░░██╗░██║░░░░░░╚████╔╝░  ██║░░░░░██║██╔██╗██║█████═╝░█████╗░░██║░░██║
// ░╚═══██╗██║██║╚████║██║░░╚██╗██║░░░░░░░╚██╔╝░░  ██║░░░░░██║██║╚████║██╔═██╗░██╔══╝░░██║░░██║
// ██████╔╝██║██║░╚███║╚██████╔╝███████╗░░░██║░░░  ███████╗██║██║░╚███║██║░╚██╗███████╗██████╔╝
// ╚═════╝░╚═╝╚═╝░░╚══╝░╚═════╝░╚══════╝░░░╚═╝░░░  ╚══════╝╚═╝╚═╝░░╚══╝╚═╝░░╚═╝╚══════╝╚═════╝░
// 
// ██╗░░░░░██╗░██████╗████████╗
// ██║░░░░░██║██╔════╝╚══██╔══╝
// ██║░░░░░██║╚█████╗░░░░██║░░░
// ██║░░░░░██║░╚═══██╗░░░██║░░░
// ███████╗██║██████╔╝░░░██║░░░
// ╚══════╝╚═╝╚═════╝░░░░╚═╝░░░
//
// The list is a dynamic data structure that is not found in 1 block, when an element is added,
// it fires where there is free space in memory and, therefore, each element must know where the next search element is found.
// The advantage of a list is that addition and deletion will have an o1 property. The size of the list is limited by the amount of memory and
// the width of the pointers. The disadvantage of the list is that you cannot access the element by index; in order to find the element,
// you must search in the list; additional memory is also spent on the beginning of storing pointers (further).
//
//         _head                          _pnext                  _pnext           _pnext
//           |                             |                       |                |
//           v                             v                       v                v
//         +---+         +---+         +---+         +---+         +---+         +---+
//         | 0 | ---->   | 0 | ---->   | 0 | ---->   | 0 | ---->   | 0 | ---->   | 0 | ----> NULLPTR.
//         +---+         +---+         +---+         +---+         +---+         +---+
//
namespace SinglyLinkedListDemo
{
	#pragma region Node struct.
	template<typename t>
	struct Node
	{
	public:
		Node* _pnext;  // Pointer to the next node.
		t _data;  // Data stored in the node.
	public:
		Node();  // Data stored in the node.
		Node(const t&);  // Constructor with data.
	};
	#pragma endregion

	template<typename T>
	class SinglyLinkedList
	{
	private:
		Node<T>* _head;  // Pointer to the head of the linked list.
		size_t _size;  // Number of elements in the linked list.
	public:
		SinglyLinkedList();  // Default constructor.
		SinglyLinkedList(const SinglyLinkedList&);  // Copy constructor.
		SinglyLinkedList(SinglyLinkedList&&);  // Move constructor.

		void push_back(const T&);  // Adds an element to the end of the list.
		void push_front(const T&);  // Adds an element to the beginning of the list.
		void pop_back();  // Removes the last element from the list.
		void pop_front();  // Removes the first element from the list.
		void remove_by_index(const size_t);  // Removes an element at the specified index.
		size_t size() const;  // Returns the number of elements in the list.
		void clear();  // Removes all elements from the list.
		void swap(SinglyLinkedList&);  // Swaps the content of two linked lists.

		SinglyLinkedList& operator=(const SinglyLinkedList&);  // Copy assignment operator.
		SinglyLinkedList&& operator=(SinglyLinkedList&&);  // Move assignment operator.
		T operator[](size_t) const;  // Returns the element at the specified index.
		
		~SinglyLinkedList() = default;  // Destructor.
	};

	#pragma region Implementation Node.
	template<typename t>
	inline Node<t>::Node()
	{
		_pnext = nullptr;
		_data = t();
	}

	template<typename t>
	inline Node<t>::Node(const t& data)
	{
		this->_pnext = nullptr;
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
			current = current->_pnext;
		}
		_size = external._size;
	}

	template<typename T>
	inline SinglyLinkedList<T>::SinglyLinkedList(SinglyLinkedList&& external)
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
			current = current->_pnext;
		}
		_size = external._size;
		external.clear();
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
	inline void SinglyLinkedList<T>::push_front(const T& meaning)
	{
		Node<T>* tmp = new Node<T>(meaning);

		if (_head == nullptr)
			_head = tmp;
		else
			tmp->_pnext = _head;

		_head = tmp;
		++_size;
	}

	template<typename T>
	inline void SinglyLinkedList<T>::pop_back()
	{
		if (_head == nullptr)
			return;
		else
		{
			Node<T>* current = _head;

			while (current->_pnext != nullptr)
				current = current->_pnext;

			delete current;
			--_size;
		}
	}

	template<typename T>
	inline void SinglyLinkedList<T>::pop_front()
	{
		if (_head == nullptr)
			return;
		else
		{
			Node<T>* tmp = _head;

			_head = _head->_pnext;
			delete tmp;
			--_size;
		}
	}

	template<typename T>
	inline void SinglyLinkedList<T>::remove_by_index(const size_t index)
	{
		if (index < 0 || index > _size)
			return;
		
		Node<T>* current = nullptr;
		
		if (index == 0)
		{
			current = _head;
			_head = _head->_pnext;
		}
		else
		{
			Node<T>* tmp = _head;

			for (size_t i = 0; i < index - 1; i++)
				tmp = tmp->_pnext;

			current = tmp->_pnext;
			tmp->_pnext = current->_pnext;
		}
		delete current;
		--_size;
	}

	template<typename T>
	inline size_t SinglyLinkedList<T>::size() const { return _size; }

	template<typename T>
	inline void SinglyLinkedList<T>::clear()
	{
		while (_size)
		{
			Node<T>* tmp = _head;

			_head = _head->_pnext;
			delete tmp;
			--_size;
		}
	}

	template<typename T>
	inline void SinglyLinkedList<T>::swap(SinglyLinkedList& meaning)
	{
		Node<T>* tmp;
		size_t tsize;

		tmp = _head;
		tsize = _size;
		_head = meaning._head;
		_size = meaning._size;
		meaning._head = tmp;
		meaning._size = tsize;
	}

	template<typename T>
	inline SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(const SinglyLinkedList& external)
	{
		Node<T>* current = external._head;
		Node<T>* new_node = nullptr;
		Node<T>* prev_node = nullptr;

		while (current != nullptr)
		{
			new_node = new Node<T>();
			new_node->_data = current->_data;

			if (current = external._head)
				_head = new_node;
			else
				prev_node->_pnext = new_node;

			prev_node = new_node;
			current = current->_pnext;
		}
		_size = external._size;
	}

	template<typename T>
	inline SinglyLinkedList<T>&& SinglyLinkedList<T>::operator=(SinglyLinkedList&& external)
	{
		Node<T>* current = external._head;
		Node<T>* new_node = nullptr;
		Node<T>* prev_node = nullptr;

		while (current != nullptr)
		{
			new_node = new Node<T>();
			new_node->_data = current->_data;

			if (current = external._head)
				_head = new_node;
			else
				prev_node->_pnext = new_node;

			prev_node = new_node;
			current = current->_pnext;
		}
		_size = external._size;
		external.clear();
	}

	template<typename T>
	inline T SinglyLinkedList<T>::operator[](size_t index) const
	{
		if (index > _size || index < 0)
			return -1;

		Node<T>* tmp = _head;

		for (size_t i = 0; i < _size; i++)
		{
			if (i == index)
				return tmp->_data;

			tmp = tmp->_pnext;
		}

		return -1;
	}
}