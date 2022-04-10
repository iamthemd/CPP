#include<iostream>
#include "SmartPtr.h"

template<typename T>
SmartPtr<T>::SmartPtr(T* p) {
	if (p == nullptr) {
		_ptr = new T();
	}
	else{
		_ptr = p;
	}
}

template<typename T>
SmartPtr<T>::~SmartPtr(){
	if (_ptr != nullptr) {
		delete _ptr;
	}
	_ptr = nullptr;
}

template<typename T>
T& SmartPtr<T>::operator*() {
	return *_ptr;
}

template<typename T>
T* SmartPtr<T>::operator->() {
	return _ptr;
}

void Test_SmartPointer() {
	SmartPtr<int> i;
	*i = 90;
	std::cout << *i << std::endl;

	SmartPtr<Test> TestPtr(new Test());
	TestPtr->a = 91;
	std::cout << TestPtr->a << std::endl;
}
