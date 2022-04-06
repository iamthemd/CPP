#include <iostream>
#include "Inheritance.h"
using namespace Inheritance;

Base::Base() {
	std::cout << "Base Class Constructor\n";
}

Derive::Derive() {
	std::cout << "Derive Class Constructor\n";
}

Derive1::Derive1() {
	std::cout << "Derive1 Class Constructor\n";
}

void Test_Inheritnce() {
	Base b;
	Derive d;
	Derive1 d1;
}
