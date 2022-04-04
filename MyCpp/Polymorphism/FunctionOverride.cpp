#include "FunctionOverride.h"

Base::Base() {
	std::cout << "Base class Constructor Called\n";
}

void Base::printString() {
	std::cout << "In Base class " << std::endl;
}

Derived::Derived() {
	std::cout << "Derived class Constructor Called\n";
}

void Derived::printString() {
	std::cout << "In Derived class" << std::endl;
}

void Test_FunctionOverride() {
	Derived d;
	d.printString();
}