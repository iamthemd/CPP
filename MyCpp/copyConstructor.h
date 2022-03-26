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
	  TestCopyConstructor(TestCopyConstructor& copyCtor) {
		  ptr = new char[strlen(copyCtor.ptr) + 1];
		  strcpy(ptr, copyCtor.ptr);
	  }
	  void changeValue(char a) {
		   ptr[0] = a;
	  }
	  void printVal() {
		  cout << "value: " << ptr << endl;
	  }
};

void Test_shallowCopy() {
	TestCopyConstructor a1("Name");
	a1.printVal();
	TestCopyConstructor a2 = a1;
	a1.changeValue('M');
	a1.printVal();
	a2.printVal();
}