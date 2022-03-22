#pragma once
#include<iostream>
using namespace std;

class TestCopyConstructor {
public: int a;
	  int* ptr;
	  TestCopyConstructor() {

	  }
	  TestCopyConstructor(TestCopyConstructor& a) {
		  ptr = new int;
		  *ptr = *(a.ptr);
	  }
	  void setValue(int a) {
		  ptr = new int();
		  *ptr = a;
	  }

	  void changeValue(int a) {
		  *ptr = a;
	  }
	  int getValue() {
		  return *ptr;
	  }
};

void Test_shallowCopy() {
	TestCopyConstructor a1;
	a1.setValue(1234);
	cout << "a1.getValue(): " << a1.getValue() << endl;
	TestCopyConstructor a2 = a1;
	a1.changeValue(4444);
	cout << "a1.getValue(): " << a1.getValue() << endl;
	cout << "a2.getValue(): " << a2.getValue() << endl;

}