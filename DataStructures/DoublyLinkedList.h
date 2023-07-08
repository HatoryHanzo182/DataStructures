#pragma once
#include "Header.h"

namespace DoublyLinkedListDemo
{
	#pragma region Node struct.
	template<typename t>
	struct Node
	{
	public:
		Node* _pnext;
		Node* _pprev;
		t _data;
	
		Node();
		Node(const t&);
	};
	#pragma endregion

	template<typename T>
	class DoublyLinkedList
	{
	private:
		Node<T>* _head;
		Node<T>* _tail;
		size_t _size;
	public:
		DoublyLinkedList();
		//DoublyLinkedList(const DoublyLinkedList&);
		//DoublyLinkedList(DoublyLinkedList&&);
		
		void push_back(const T&);  // Adds an element to the end of the list.
		void push_front(const T&);  // Adds an element to the beginning of the list.
		//void pop_back();  // Removes the last element from the list.
		//void pop_front();  // Removes the first element from the list.
		//void remove_by_index(const size_t);  // Removes an element at the specified index.
		size_t size() const;  // Returns the number of elements in the list.
		//void clear();  // Removes all elements from the list.
		//void swap(SinglyLinkedList&);  // Swaps the content of two linked lists.
		//
		//DoublyLinkedList& operator=(const DoublyLinkedList&);
		//DoublyLinkedList& operator=(DoublyLinkedList&&);
		T operator[](size_t);

		~DoublyLinkedList() = default;
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
	inline size_t DoublyLinkedList<T>::size() const { return _size; }

	template<typename T>
	inline T DoublyLinkedList<T>::operator[](size_t index)
	{
		if (index > _size || index < 0)
			return -1;

		Node<T>* tmp = _head;

		for (size_t i = 0; i < index; i++)
			tmp = tmp->_pnext;

		return tmp->_data;
	}
}