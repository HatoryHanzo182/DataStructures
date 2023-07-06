#pragma once
#include "Header.h"

//
//	██╗░░░░░██╗███████╗░█████╗░
//	██║░░░░░██║██╔════╝██╔══██╗
//	██║░░░░░██║█████╗░░██║░░██║
//	██║░░░░░██║██╔══╝░░██║░░██║
//	███████╗██║██║░░░░░╚█████╔╝
//	╚══════╝╚═╝╚═╝░░░░░░╚════╝░
// 
// Stack - a data structure that allows you to add new elements and remove existing ones only from 1 end, respectively,
// the last added element will be the first to be removed, (Last In First Out).
// Usually the stack provides 3 main methods: Push, Pop, Peek - view the top element.
//
//      +---+         +---+         +---+         +---+         +---+
//      | 4 |         | 2 |         | 7 |         | 5 |         | 9 |
//      +---+         +---+         +---+         +---+         +---+
//        ^                                                       ^
//        |                                                       |
//       Top                                                    Bottom
//

namespace StackDemo
{
	template<typename T>
	class Stack
	{
	private:
		T* _data;  // Essentially a pointer to the contents of our data.
		size_t _size;  // Number of elements stored.
	public:
		explicit Stack();  // Default constructor
		Stack(const Stack&);  // The semantics of copying and moving, since after 
		Stack(Stack&&);		 // our class the pointer standard will not work.

		void push(T);  // The method adds our data.
		void pop();  // Removes the last added element.
		T peek();	// Shows the last element.
		void swap(Stack&);  // Swaps class data with data of the same data type.
		bool empty();  // Checks if the stack was empty.
		size_t size();  // Returns the size.

		Stack& operator=(const Stack&);  // Operator overloading for copy-and-move semantics 
		Stack& operator=(Stack&&);      // in case data will be created based on an existing.
		T& operator[](size_t);  // Returns index.

		~Stack();  // Destructor.
	};

	#pragma region Implementation.
	template<typename T>
	inline Stack<T>::Stack()
	{
		_data = nullptr;
		_size = 0;
	}

	template<typename T>
	inline Stack<T>::Stack(const Stack& external)
	{
		this->_data = new T[external._size];
		this->_size = external._size;

		for (size_t i = 0; i < _size; i++)
			this->_data[i] = external._data[i];
	}

	template<typename T>
	inline Stack<T>::Stack(Stack&& external)
	{
		this->_data = new T[external._size];
		this->_size = external._size;

		for (size_t i = 0; i < _size; i++)
			this->_data[i] = external._data[i];

		delete[] external._data;
		external._data = nullptr;
		external._size = 0;
	}

	template<typename T>
	inline void Stack<T>::push(T meaning)
	{
		T* tmp = new T[_size + 1];

		for (size_t i = 0; i < _size; i++)
			tmp[i + 1] = _data[i];

		tmp[0] = meaning;
		delete[] _data;
		_data = tmp;
		++_size;
	}

	template<typename T>
	inline void Stack<T>::pop()
	{
		T* tmp = new T[_size - 1];

		for (size_t i = 1; i < _size; i++)
			tmp[i - 1] = _data[i];

		delete[] _data;
		_data = tmp;
		--_size;
	}

	template<typename T>
	inline T Stack<T>::peek() { return _data[0]; }

	template<typename T>
	inline void Stack<T>::swap(Stack& external)
	{
		if (this != &external)
		{
			T* tmp = new T[_size];
			size_t tsize = _size;

			for (size_t i = 0; i < _size; i++)
				tmp[i] = _data[i];

			delete[] _data;
			_data = new T[external._size];

			for (size_t i = 0; i < external._size; i++)
				_data[i] = external._data[i];

			delete[] external._data;
			external._data = tmp;

			_size = external._size;
			external._size = tsize;
		}
	}

	template<typename T>
	inline bool Stack<T>::empty() { return _size; }

	template<typename T>
	inline size_t Stack<T>::size() { return _size; }

	template<typename T>
	inline Stack<T>& Stack<T>::operator=(const Stack& external)
	{
		if (this != &external)
		{
			delete[] _data;
			this->_data = new T[external._size];
			this->_size = external._size;

			for (size_t i = 0; i < _size; i++)
				this->_data[i] = external._data[i];
		}
		return *this;
	}

	template<typename T>
	inline Stack<T>& Stack<T>::operator=(Stack&& external)
	{
		if (this != &external)
		{
			delete[] _data;
			this->_data = new T[external._size];
			this->_size = external._size;

			for (size_t i = 0; i < _size; i++)
				this->_data[i] = external._data[i];

			delete[] external._data;
			external._data = nullptr;
			external._size = 0;
		}
		return *this;
	}

	template<typename T>
	inline T& Stack<T>::operator[](size_t meaning) { return _data[meaning]; }

	template<typename T>
	inline Stack<T>::~Stack()
	{
		if (_data != nullptr)
			delete[] _data;
		_size = 0;
	}
#pragma endregion
}
