#pragma once
#include "Header.h"

namespace DoublyLinkedListDemo
{
	#pragma region Node struct.
	template<typename t>
	struct Node
	{
	public:
		Node* _pnext;  // Pointer to the next list node.
		Node* _pprev;  // Pointer to the Sunday list.
		t _data;  // Data stored in the node.
	
		Node();  // Default constructor.
		Node(const t&);  // Constructor with a parameter, which takes data to be stored in the node.
	};
	#pragma endregion

	template<typename T>
	class DoublyLinkedList
	{
	private:
		Node<T>* _head;	 // Pointer to the first node in the list.
		Node<T>* _tail;	 // Pointer to the last node in the list.
		size_t _size;  // Number of elements in the list.
	public:
		DoublyLinkedList();  // Default constructor.
	    DoublyLinkedList(const DoublyLinkedList&);  // Copy constructor.
		DoublyLinkedList(DoublyLinkedList&&);  // Move constructor.
		
		void push_back(const T&);  // Adds an element to the end of the list.
		void push_front(const T&);  // Adds an element to the beginning of the list.
		void pop_back();  // Removes the last element from the list.
		void pop_front();  // Removes the first element from the list.
		void remove_by_index(const size_t);  // Removes an element at the specified index.
		size_t size() const;  // Returns the number of elements in the list.
		void clear();  // Removes all elements from the list.
		void swap(DoublyLinkedList&);  // Swaps the content of two linked lists.
		
		DoublyLinkedList& operator=(const DoublyLinkedList&);  // Copy assignment operator.
		DoublyLinkedList& operator=(DoublyLinkedList&&);  // Move assignment operator.
		T operator[](size_t);  // Accesses the element at the specified index.

		~DoublyLinkedList() = default;  // Destructor.
	};

	#pragma region Implementation Node.
	template<typename t>
	inline Node<t>::Node()
	{
		this->_pnext = nullptr;
		this->_pprev = nullptr;
		this->_data = t();
	}

	template<typename t>
	inline Node<t>::Node(const t& data)
	{
		this->_pnext = nullptr;
		this->_pprev = nullptr;
		this->_data = data;
	}
	#pragma endregion

	template<typename T>
	inline DoublyLinkedList<T>::DoublyLinkedList()
	{
		this->_head = nullptr;
		this->_tail = nullptr;
		this->_size = size_t();
	}

	template<typename T>
	inline DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& external)
	{
		_head = external._head;
		_tail = external._tail;
		_size = external._size;
	}

	template<typename T>
	inline DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList&& external)
	{
		_head = external._head;
		_tail = external._tail;
		_size = external._size;
		external.clear();
	}

	template<typename T>
	inline void DoublyLinkedList<T>::push_back(const T& meaning)
	{
		Node<T>* tmp = new Node<T>(meaning);

		if (_head == nullptr)
			_head = tmp;
		else
		{
			_tail->_pnext = tmp;
			tmp->_pprev = _tail;
		}
		_tail = tmp;
		++_size;
	}

	template<typename T>
	inline void DoublyLinkedList<T>::push_front(const T& meaning)
	{
		Node<T>* tmp = new Node<T>(meaning);

		if (_head == nullptr)
			_head = tmp;
		else
		{
			_head->_pprev = tmp;
			tmp->_pnext = _head;
		}
		_head = tmp;
		++_size;
	}

	template<typename T>
	inline void DoublyLinkedList<T>::pop_back()
	{
		Node<T>* tmp = new Node<T>();

		if (_head == nullptr)
			return;
		else
		{
			tmp = _tail->_pprev;
			tmp->_pnext = nullptr;
			_tail = tmp;
			--_size;
		}
	}

	template<typename T>
	inline void DoublyLinkedList<T>::pop_front()
	{
		Node<T>* tmp = new Node<T>();

		if (_head == nullptr)
			return;
		else
		{
			tmp = _head->_pnext;
			tmp->_pprev = nullptr;
			_head = tmp;
			--_size;
		}
	}

	template<typename T>
	inline void DoublyLinkedList<T>::remove_by_index(const size_t index)
	{
		if (index > _size || index < 0)
			return;


		if (index == 0 && _head->_pnext)
		{
			Node<T>* tmp = _head;

			_head = _head->_pnext;
			_head->_pprev = nullptr;
			delete tmp;
			_size--;
			return;
		}
		else if (index == 1 && _head == _tail)
		{
			_head->_pnext = nullptr;
			_head = nullptr;
			delete _head;
			_size = 0;
			return;
		}
		if (index == _size)
		{
			Node<T>* tmp = _tail;

			_tail = _tail->_pprev;
			_tail->_pnext = nullptr;
			delete tmp;
			_size--;
			return;
		}

		Node<T>* tmp = _head;
		Node<T>* tmp2;

		for (size_t i = 0; i < index - 1; i++)
			tmp = tmp->_pnext;

		tmp2 = tmp;
		tmp2->_pprev->_pnext = tmp->_pnext;
		tmp2->_pnext->_pprev = tmp->_pprev;
		delete tmp;
		_size--;
	}

	template<typename T>
	inline size_t DoublyLinkedList<T>::size() const { return _size; }

	template<typename T>
	inline void DoublyLinkedList<T>::clear()
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
	inline void DoublyLinkedList<T>::swap(DoublyLinkedList& meaning)
	{
		Node<T>* tmp;
		size_t tsize = _size;

		tmp = _head;
		_head = meaning._head;
		meaning._head = tmp;
		_size = meaning._size;
		meaning._size = tsize;
		delete tmp;
	}

	template<typename T>
	inline DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList& external)
	{
		_head = external._head;
		_tail = external._tail;
		_size = external._size;

		return *this;
	}

	template<typename T>
	inline DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(DoublyLinkedList&& external)
	{
		_head = external._head;
		_tail = external._tail;
		_size = external._size;
		external.clear;

		return *this;
	}

	template<typename T>
	inline T DoublyLinkedList<T>::operator[](size_t index)
	{
		if (index >= _size)
			return -1;

		Node<T>* tmp = _head;

		for (size_t i = 0; i < index; i++)
			tmp = tmp->_pnext;

		return tmp->_data;
	}
}