#include<iostream>
#include "SmartPtr.h"

Test::Test() {
	std::cout << "Test Constructor\n" << std::endl;
}

Test::~Test() {
	std::cout << "Test Destructor\n" << std::endl;
}

template<typename T>
SmartPtr<T>::SmartPtr(T* p) {
		_ptr = p;
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

void PassIn(std::unique_ptr<Test> ptr) {
	std::cout << "PassIN takes Owner ship of TestUniquePtr2\n";
	std::cout << ptr->a << std::endl;
}

std::unique_ptr<Test> Passout() {
	auto ptr = std::make_unique<Test>();
	ptr->a = 9879;
	return ptr;
}

void Test_SmartPointer() {
	SmartPtr<int> i;
	*i = 90;
	std::cout << *i << std::endl;

	SmartPtr<Test> TestPtr(new Test());
	TestPtr->a = 91;
	std::cout << TestPtr->a << std::endl;

	// ---------------------- unique_ptr ------------------------------ //
	// One copy of object exists only
	// we can transfer the ownership using move semantic, can't copy. that's why it called one ownership.
	std::unique_ptr<Test> TestUniquePtr(new Test());
	TestUniquePtr->a = 20;

	std::unique_ptr<Test> TestUniquePtr2;
	TestUniquePtr2 = std::move(TestUniquePtr);
	std::cout << TestUniquePtr2->a << std::endl;
	
	PassIn(std::move(TestUniquePtr2));
	if (TestUniquePtr2) {
		std::cout << "TestUniquePtr2: is not Mpty\n";
	}
	else {
		std::cout << "TestUniquePtr2: is Mpty!\n";
	}

	TestUniquePtr2 = Passout();
	if (TestUniquePtr2) {
		std::cout << "TestUniquePtr2: is not Mpty\n";
		std::cout << "Value of member a of TestUniquePtr2 is : " << TestUniquePtr2->a << std::endl;
	}
	else {
		std::cout << "TestUniquePtr2: is Mpty!\n";
	}
	
	// ---------------------- shared_ptr ------------------------------ //
	// Shared the ownership and every share it increase the count of ownership
	// The object is destroy and memory deallocate only last remaining shared_ptr owning the object is destroyed;
	std::shared_ptr<Test> TestSharedPtr(new Test());
	TestSharedPtr->a = 99;
	{
	std::shared_ptr<Test> TestSharedPtr2 = TestSharedPtr;
	TestSharedPtr2->a = 9;
	std::cout << "count Ownership: " << TestSharedPtr.use_count() << std::endl;
	std::cout << "TestSharedPtr->a: " << TestSharedPtr->a << std::endl;
	std::cout << "TestSharedPtr2->a: " << TestSharedPtr2->a << std::endl;
	}

	std::cout << "count Ownership: " << TestSharedPtr.use_count() << std::endl;
	std::cout << "TestSharedPtr->a: " << TestSharedPtr->a << std::endl;

}
