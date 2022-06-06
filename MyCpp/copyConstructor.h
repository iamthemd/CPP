#pragma once
#include<iostream>
#include <string>

using namespace std;

class TestCopyConstructor {
	char* ptr;
public:
	TestCopyConstructor(const char* charPtr) {
		ptr = new char[strlen(charPtr) + 1];
		strcpy(ptr, charPtr);
	}
	TestCopyConstructor(const TestCopyConstructor& copyCtor) {
		ptr = new char[strlen(copyCtor.ptr) + 1];
		strcpy(ptr, copyCtor.ptr);
	}

	TestCopyConstructor& operator = (const TestCopyConstructor& copyCtor) {
		if (this == &copyCtor) {
			return *this;
		}
		ptr = new char[strlen(copyCtor.ptr) + 1];
		strcpy(ptr, copyCtor.ptr);
		return *this;
	}
	void changeValue(char a) {
		ptr[0] = a;
	}
	void printVal() {
		cout << "value: " << ptr << endl;
	}
};

TestCopyConstructor& fun() {
	TestCopyConstructor t("Number");
	return t;
}
void Test_shallowCopy() {
	TestCopyConstructor a1("Name");
	a1.printVal();
	TestCopyConstructor a2 = a1;
	a1.changeValue('M');
	a1.printVal();
	a2.printVal();

	// Why we need const in copyConstructor?
	// Remove const from Copyconstructor and enable below code and compile programm
	// The function fun() return by value, compiler create temporary object which is 
	// copied to t3 using copy constructor. The reason for compiler error is compiler 
	// created temporary object can not be bound to non-const reference.
	// 
	TestCopyConstructor t3 = fun();
}