#pragma once
#include "Header.h"

//
// ███████╗██╗███████╗░█████╗░
// ██╔════╝██║██╔════╝██╔══██╗
// █████╗░░██║█████╗░░██║░░██║
// ██╔══╝░░██║██╔══╝░░██║░░██║
// ██║░░░░░██║██║░░░░░╚█████╔╝
// ╚═╝░░░░░╚═╝╚═╝░░░░░░╚════╝░
// 
// Queue - a data structure that allows you to store many elements of the same type,
// but elements are always added at the end of the queue, and are removed from the beginning of the queue, 
// so the first added element will be removed (First In First Out). The queue has the main methods:
// Push, Pop - allows you to get 1 element.
// 
//  +		    +++++		  +
//  +		    +++++		  +
//  +		    +++++		  +
//  +		    +++++	          +
//  +		    +++++		  +
//  +		    +++++		  +
//  +		  +++++++++		  +
//  +		   +++++++		  +
//  +		    +++++		  +
//  +		     +++		  +
//  +		      +			  +
//  +					  +
//  +	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0   +
//  +	0			      0	  +
//  +	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0	  +
//  +					  +
//  +   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0	  +
//  +   0			      0	  +
//  +   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0	  +
//  +					  +
//  +   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0	  +
//  +   0			      0	  +
//  +   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0   +
//  +					  +
//  +		    +++++		  +
//  +		    +++++		  +
//  +		    +++++		  +
//  +		    +++++	          +
//  +		    +++++		  +
//  +		    +++++		  +
//  +		  +++++++++		  +
//  +		   +++++++		  +
//  +		    +++++		  +
//  +		     +++		  +
//  +		      +			  +
//


namespace QueueDemo
{
	template<typename T>
	class Queue
	{
	private:
		T* _data;  // Pointer to data array.
		size_t _size;  // Queue size.
	public:
		explicit Queue();  // Default constructor.
		Queue(const Queue&);  // Copy constructor.
		Queue(Queue&&);  // Move constructor.
		
		void push(T);  // Adds an element to the end of the queue.
		void pop();  // Removes an element from the front of the queue.
		T front();  // Returns the first element of the queue.
		T back();  // Returns the last element of the queue.
		void swap(Queue&);  // Exchanges the contents of a queue with another queue.
		bool empty();  // Checks if the queue is empty.
		size_t size() const;  // Returns the size of the queue.
		
		Queue& operator=(const Queue&);  // Copy assignment operator.
		Queue operator=(Queue&&);  // Move assignment operator.
		T& operator[](size_t);  // Index access operator.
		
		~Queue();  // Destructor.
	};

	#pragma region Implementation.
	template<typename T>
	inline Queue<T>::Queue()
	{
		_data = nullptr;
		_size = 0;
	}

	template<typename T>
	inline Queue<T>::Queue(const Queue& external)
	{
		this->_data = new T[external];
		this->_size = external._size;

		for (size_t i = 0; i < _size; i++)
			this->_data[i] = external._data[i];
	}

	template<typename T>
	inline Queue<T>::Queue(Queue&& external)
	{
		this->_data = new T[external];
		this->_size = external._size;

		for (size_t i = 0; i < _size; i++)
			this->_data[i] = external._data[i];

		delete[] external._data;
		external._data = nullptr;
		external._size = 0;
	}

	template<typename T>
	inline void Queue<T>::push(T meaning)
	{
		T* tmp = new T[_size + 1];

		for (size_t i = 0; i < _size; i++)
			tmp[i] = _data[i];

		tmp[_size] = meaning;
		delete[] _data;
		_data = tmp;
		++_size;
	}

	template<typename T>
	inline void Queue<T>::pop()
	{
		T* tmp = new T[_size - 1];

		for (size_t i = 1; i < _size; i++)
			tmp[i - 1] = _data[i];

		delete[] _data;
		_data = tmp;
		--_size;
	}

	template<typename T>
	inline T Queue<T>::front() { return _data[0]; }

	template<typename T>
	inline T Queue<T>::back() { return _data[_size - 1]; }

	template<typename T>
	inline void Queue<T>::swap(Queue& external)
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
	inline bool Queue<T>::empty() { return _size; }

	template<typename T>
	inline size_t Queue<T>::size() const { return _size; }

	template<typename T>
	inline Queue<T>& Queue<T>::operator=(const Queue& external)
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
	inline Queue<T> Queue<T>::operator=(Queue&& external)
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
	inline T& Queue<T>::operator[](size_t meaning) { return _data[meaning]; }

	template<typename T>
	inline Queue<T>::~Queue()
	{
		if (_data != nullptr)
		{
			delete[] _data;
			_size = 0;
		}
	}
#pragma endregion
}
