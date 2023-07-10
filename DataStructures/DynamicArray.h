#pragma once
#include "Header.h"

namespace DynamicArrayDemo
{
	template<typename T>
	class DynamicArr
	{
	private:
		T* _data;
		size_t _size;
	public:
		explicit DynamicArr();
		explicit DynamicArr(const T);
		DynamicArr(const DynamicArr&);
		DynamicArr(DynamicArr&&);

		void push_back(const T);
		void remove_index(const size_t);
		void remove(const T);
		void insert(const size_t, const T);
		void swap(DynamicArr<T>&);
		size_t size();
		
		DynamicArr<T>& operator=(const DynamicArr<T>&);
		DynamicArr<T>& operator=(DynamicArr<T>&&);
		T operator[](size_t);

		~DynamicArr();
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