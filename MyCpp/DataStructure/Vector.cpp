#include "Vector.h"

template <typename T>
Vector<T>::Vector() {
	_size = 0;
	_dArray = nullptr;
	_capacity = 0;
}

template<typename T>
Vector<T>::Vector(unsigned int size) {
	_size = 0;
	if (_dArray != nullptr) {
		delete _dArray;
		_dArray = nullptr;
	}
	_dArray = new T[size];
	_capacity = size;
}

template<typename T>
void Vector<T>::push_back(const T& element) {
	if (_size == _capacity) {
		resize(_size + __RESIZE_VECTOR_CHUNK__);
	}
	_dArray[_size] = element;
	_size++;
}

template<typename T>
void Vector<T>::pop_back() {
	if (_size == 0) {
		std::cout << "Empty Vector\n";
	}
	else {
		std::cout << "Element Pop_back: " << std::endl;
		_dArray[_size];
	}
}

template<typename T>
void Vector<T>::resize(unsigned int size) {
	if (_dArray != nullptr) {
		T* ptr = new T[size];
		int i = 0;
		while (i < _size)
		{
			ptr[i] = _dArray[i];
		}
		delete[] _dArray;
		_dArray = nullptr;
		_dArray = ptr;
	}
}


template<typename T>
Vector<T>::~Vector()
{
	delete [] _dArray;
}
