#pragma once
#include<iostream>

namespace Conversion{
class B;
class A {
	int a;
public:
	A() {}
	A(int x) :a(x) {}
	
	int getVal() { return a; }
};

class B {
	int b;
public:
	B() {}
	B(int x) :b(x) {}
	B(A aObj) {
		b = aObj.getVal();
	}
	int getVal() { return b; }
};
}


void Test_ClassToClass() {
	std::cout << "----------------- ClassToClass --------------------\n";

	Conversion::A a1(1);
	Conversion::B b1(2);

	b1 = a1;
	std::cout << "b1.getVal():" << b1.getVal() << std::endl;
	std::cout << "a1.getVal():" << a1.getVal() << std::endl;

	
}
