#pragma once
#include <iostream>
using namespace std;

class ConstructorClass {
public:
	ConstructorClass() {
		cout << "default Constructor\n";
		intA = NULL;
	}

	ConstructorClass(int a) {
		cout << "Parametrized constructor\n";
		intA = a;
	}

	void setIntA(int a) {
		intA = a;
	}

	void printIntA() {
		cout << "value of " << intA << endl;
	}
	int intA;
};

void testFunction(ConstructorClass obj) {
	obj.intA = 123;
}


void Test_Constructor() {
	ConstructorClass obj;
	obj.setIntA(456);
	obj.printIntA();
	testFunction(obj);
	obj.printIntA();
}