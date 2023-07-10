#pragma once
#include "Header.h"

//
//██████╗░██╗░░░██╗███╗░░██╗░█████╗░███╗░░░███╗██╗░█████╗░  ░█████╗░██████╗░██████╗░░█████╗░██╗░░░██╗
//██╔══██╗╚██╗░██╔╝████╗░██║██╔══██╗████╗░████║██║██╔══██╗  ██╔══██╗██╔══██╗██╔══██╗██╔══██╗╚██╗░██╔╝
//██║░░██║░╚████╔╝░██╔██╗██║███████║██╔████╔██║██║██║░░╚═╝  ███████║██████╔╝██████╔╝███████║░╚████╔╝░
//██║░░██║░░╚██╔╝░░██║╚████║██╔══██║██║╚██╔╝██║██║██║░░██╗  ██╔══██║██╔══██╗██╔══██╗██╔══██║░░╚██╔╝░░
//██████╔╝░░░██║░░░██║░╚███║██║░░██║██║░╚═╝░██║██║╚█████╔╝  ██║░░██║██║░░██║██║░░██║██║░░██║░░░██║░░░
//╚═════╝░░░░╚═╝░░░╚═╝░░╚══╝╚═╝░░╚═╝╚═╝░░░░░╚═╝╚═╝░╚════╝░  ╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░
//
// A dynamic array, also known as a resizable array or a dynamically allocated array, is a data structure that allows
// the allocation and deallocation of memory at runtime to store a collection of elements. Unlike static arrays, 
// which have a fixed size determined at compile time, dynamic arrays can grow or shrink in size as needed.
// 
// Dynamic arrays are implemented using pointers and dynamically allocated memory.
// The elements of the array are stored in a contiguous block of memory, and the pointer 
// keeps track of the starting address of this block.
// 
// +---+ +---+ +---+ +---+ +---+
// | 1 | | 3 | | 2 | | 0 | | 9 |
// +---+ +---+ +---+ +---+ +---+ 
//
namespace DynamicArrayDemo
{
	template<typename T>
	class DynamicArr
	{
	private:
		T* _data;  // Pointer to the dynamic array data.
		size_t _size;  // Size of the dynamic array.
	public:
		explicit DynamicArr();  // Default constructor.
		explicit DynamicArr(const T);  // Constructor with initial value.
		DynamicArr(const DynamicArr&);  // Copy constructor.
		DynamicArr(DynamicArr&&);  // Move constructor.

		void push_back(const T);  // Add an element at the end of the array.
		void remove_index(const size_t);  // Remove an element at a specific index.
		void remove(const T);  // Remove the first occurrence of a value.
		void insert(const size_t, const T);  // Insert an element at a specific index.
		void swap(DynamicArr<T>&);  // Swap the content of two arrays.
		size_t size();  // Get the size of the array.
		
		DynamicArr<T>& operator=(const DynamicArr<T>&);  // Copy assignment operator.
		DynamicArr<T>& operator=(DynamicArr<T>&&);  // Move assignment operator.
		T operator[](size_t); // Access element at a specific index.

		~DynamicArr();  // Destructor.
	};

	#pragma region Implementation.
	template<typename T>
	inline DynamicArr<T>::DynamicArr()
	{
		this->_data = nullptr;
		size_t _size = size_t();
	}

	template<typename T>
	inline DynamicArr<T>::DynamicArr(const T data) { push_back(data); }

	template<typename T>
	inline DynamicArr<T>::DynamicArr(const DynamicArr& external)
	{
		delete[] _data;
		_data = new T[external._size];
		_size = external._size;

		for (size_t i = 0; i < external._size; i++)
			_data[i] = external[i];
	}

	template<typename T>
	inline DynamicArr<T>::DynamicArr(DynamicArr&& external)
	{
		delete[] _data;
		_data = new T[external._size];
		_size = external._size;

		for (size_t i = 0; i < external._size; i++)
			_data[i] = external[i];

		delete[] external._data;
		external._size = 0;
	}

	template<typename T>
	inline void DynamicArr<T>::push_back(const T data)
	{
		T* tmp = new T[_size + 1];

		for (size_t i = 0; i < _size; i++)
			tmp[i] = _data[i];

		tmp[_size] = data;
		delete _data;
		_data = tmp;
		_size++;
	}

	template<typename T>
	inline void DynamicArr<T>::remove_index(const size_t index)
	{
		if (index > _size)
			return;
		
		T* tmp = new T[_size - 1];

		for (size_t i = 0, j = 0; i < _size; i++)
		{
			if (i == index)
				continue;
			tmp[j++] = _data[i];
		}

		delete[] _data;
		_data = tmp;
		_size--;
	}

	template<typename T>
	inline void DynamicArr<T>::remove(const T data)
	{
		T* tmp = new T[_size - 1];

		for (size_t i = 0, j = 0; i < _size; i++)
		{
			if (_data[i] == data)
				continue;
			tmp[j++] = _data[i];
		}

		delete[] _data;
		_data = tmp;
		_size--;
	}

	template<typename T>
	inline void DynamicArr<T>::insert(const size_t index, const T data)
	{
		if (index > _size)
			return;
		else if (index == _size)
			push_back(data);

		T* tmp = new T[_size + 1];

		for (size_t i = 0, j = 0; i < _size;)
		{
			if (i == index)
				tmp[j++] = data;
			tmp[j++] = _data[i++];
		}

		delete[] _data;
		_data = tmp;
		_size++;
	}

	template<typename T>
	inline void DynamicArr<T>::swap(DynamicArr<T>& external)
	{
		T* tmp = new T[_size];
		size_t tsize = 0;

		for (size_t i = 0; i < _size; i++)
			tmp[i] = _data[i];

		delete[] _data;
		_data = new T[external._size];

		for (size_t i = 0; i < external._size; i++)
			_data[i] = external._data[i];

		delete[] external._data;
		external._data = new T[_size];

		for (size_t i = 0; i < _size; i++)
			external._data[i] = tmp[i];

		delete[] tmp;
		tsize = _size;
		_size = external._size;
		external._size = tsize;
	}

	template<typename T>
	inline size_t DynamicArr<T>::size() { return _size; }

	template<typename T>
	inline DynamicArr<T>& DynamicArr<T>::operator=(const DynamicArr<T>& external)
	{
		delete[] _data;
		_data = new T[external._size];
		_size = external._size;

		for (size_t i = 0; i < external._size; i++)
			_data[i] = external[i];

		return *this;
	}

	template<typename T>
	inline DynamicArr<T>& DynamicArr<T>::operator=(DynamicArr<T>&& external)
	{
		delete[] _data;
		_data = new T[external._size];
		_size = external._size;

		for (size_t i = 0; i < external._size; i++)
			_data[i] = external[i];

		delete[] external._data;
		external._size = 0;

		return *this;
	}

	template<typename T>
	inline T DynamicArr<T>::operator[](size_t index) { return _data[index]; }

	template<typename T>
	inline DynamicArr<T>::~DynamicArr()
	{
		delete[] _data;
		_size = 0;
	}
	#pragma endregion
}