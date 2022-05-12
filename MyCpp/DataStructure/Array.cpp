#include <iostream>
#include "array.h"

template <class T, size_t _size>
int  StaticArray<T, _size>::front() {
	return _array[0];
}

template <class T, size_t _size>
int StaticArray<T, _size>::back() {
	return _array[_size - 1];
}

template <class T, size_t _size>
size_t StaticArray<T, _size>::size() const {
	return _size;
}

template<class T, size_t _size>
int& StaticArray<T, _size>::operator [](int index) {
	if (index < _size) {
		return _array[index];
	}
	else {
		std::cout << "Error: outof index \n";
	}
}

template<class T, size_t _size>
int& StaticArray<T, _size>::at(int index) {
	if (index < _size) {
		return _array[index];
	}
	else {
		std::cout << "Error: outof index \n";
	}
}

template<class T, size_t _size>
void StaticArray<T, _size>::swap(StaticArray<T, _size>& rhs) {
	for (int i = 0; i < _size; i++) {
		T temp;
		temp = std::move(_array[i]);
		_array[i] = std::move(rhs[i]);
		rhs[i]= std::move(temp);
	}
}

void Test_StaticArray() {
	StaticArray<int, 10> stArray, st2;
	for (int i = 0; i < 10; i++) {
		stArray[i] = i * 10;
		st2[i] = 11 + i;
	}

	stArray.at(5) = 6;
	for (int i = 0; i < 10; i++) {
		std::cout << stArray[i] << " ";
	}

	std::cout << "Front: " << stArray.front() << std::endl;
	std::cout << "Back: " << stArray.back() << std::endl;
	stArray.swap(st2);
	for (int i = 0; i < 10; i++) {
		std::cout << stArray[i] << " ";
	}

	std::cout << "-------------------- Test Iterator ---------------- /n";
	for (auto itr = stArray.begin(); itr != stArray.end(); itr++) {
		std::cout << *itr << " ";
	}
}