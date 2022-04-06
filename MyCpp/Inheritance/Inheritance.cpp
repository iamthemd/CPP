#include <iostream>
#include "Inheritance.h"
using namespace Inheritance;

Base::Base() {
	std::cout << "Base Class Constructor\n";
}

Base::~Base() {
	std::cout << "Base Class Destructor\n";
}

Derive::Derive() {
	std::cout << "Derive Class Constructor\n";
}

Derive::~Derive() {
	std::cout << "Derive Class Destructor\n";
}

Derive1::Derive1() {
	std::cout << "Derive1 Class Constructor\n";
}

Derive1::~Derive1() {
	std::cout << "Derive1 Class Destructor\n";
}

void Test_Inheritnce() {
	// Base Class Constructor first called then Derive class constructor called.
	// In Destructor case first derive class destructor destruct then base class destructor
	Base b;
	Derive d;
	Derive1 d1;

}
