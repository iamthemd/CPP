#pragma once
#include<iostream>
using namespace std;

//static datamember are not included in the sizeof  object or class because they are common to all.
class MyStaticClass {
public:
	int x;
	static int y;

	void set() {
		y = 123;
	}
	int get() {
		return y;
	}

	void change(int a) {
		y = a;
	}

	static void staticFunction()
	{
		// x = 90; <--- It gieves error as static function can only access static datamember
		// Becuase only static function can be invoke withous object means it can be invoke by className
		// For ex: MyStaticClass::staticFunction
		cout << "In StaticFunction...\n" << endl;
	}
};

int MyStaticClass::y; // Declaration for static is mandatory.

void Test_Static() {
	MyStaticClass obj, obj1;
	obj.set();
	cout << "Value:" << obj1.get() << endl;
	obj1.change(4567);
	cout << "Value:" << obj.get() << endl;
	cout << "Size of MyStaticClass is :" << sizeof(MyStaticClass) << endl;

	MyStaticClass::staticFunction();
}
