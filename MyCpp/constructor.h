#pragma once
#include <iostream>
using namespace std;

/*
* - Constructor is a special membere function whose task is to intiialise the object of its class.
* - It is a special  member funtion becase name is the same as class name and it doesn't have retur type.
* - Constructor is invoked whenver object of associated class is being created.
* - It doesn't require external invokation like normal function.
* - If programmer provide constructor externally compiler dropeed default constructor.
* - Types of Conostructor:
*   i) default constructor.
*   ii) Copy constructor.
*   iii) Parameterizex constructor.
*   iv) dynamic constructor.
*/
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