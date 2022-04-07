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

Single::Single() {
	std::cout << "Single Class Constructor\n";
}

Single::~Single() {
	std::cout << "Single Class Destructor\n";
}

Multilevel::Multilevel() {
	std::cout << "Multilevel Class Constructor\n";
}

Multilevel::~Multilevel() {
	std::cout << "Multilevel Class Destructor\n";
}

Multiple::Multiple() {
	std::cout << "Multiple Class Constructor\n";
}

Multiple::~Multiple() {
	std::cout << "Multiple class Destructor\n";
}

Single1::Single1()
{
	std::cout << "Single class Constructor\n";
}

Single1::~Single1()
{
	std::cout << "Single1 Destructor\n";
}

Hybrid::Hybrid()
{
	std::cout << "In Hybrid Constructor\n";
}

Hybrid::~Hybrid()
{
	std::cout << "In Hybrid Destructor\n";
}


void Test_Inheritnce() {
	// Base Class Constructor first called then Derive class constructor called.
	// In Destructor case first derive class destructor destruct then base class destructor
	//Base b;
	//Single d;
	//Multilevel d1;
	//Multiple mp;
	
	// Check out put for hybrid, two copy of base class created. 
	// To resolve or avoid tow copy of base class we need to inherit base class as virtual
	// for both single and single1
	// for ex: class single: virtual public Base{}; class single1: virtual public Base{};
	Hybrid h;
}




