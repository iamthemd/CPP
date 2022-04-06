#include<iostream>

#include "VirtualConcept.h"

// ----------------- Base Class ------------------- //
BaseClass::BaseClass() {
	std::cout << "In base class constructor\n";
}

void BaseClass::print() {
	std::cout << "In Base class print function\n";
}

void BaseClass::fun1_virtual() {
	std::cout << "Base Class: func1_vritaul()\n";
}

void BaseClass::fun2_virtual() {
	std::cout << "Base Class: func2_virtual()\n";
}

// ----------------- Derive Class ------------------- //
DerivedClass::DerivedClass() {
	std::cout << "In derived class constructor\n";
}

void DerivedClass::print() {
	std::cout << "In Derived class print function\n";
}

void DerivedClass::fun1_virtual() {
	std::cout << "Derived Class: func1_virtual()\n";
}

// ----------------- Second derive Class ------------------- //
SecondDeriveClass::SecondDeriveClass() {
	std::cout << "In Second Derive Class constructor\n";
}

void SecondDeriveClass::print() {
	std::cout << "In second derive class print function\n";
}

void SecondDeriveClass::fun2_virtual() {
	std::cout << "Second DeriveClass: func2_virtual()\n";
}

void Test_VirtualConcept() {
	BaseClass *basePtr;
	DerivedClass derivedObj;
	SecondDeriveClass sDeriveObj;
	
	basePtr = &derivedObj;
	basePtr->print();
	basePtr->fun1_virtual();
	basePtr->fun2_virtual();

	basePtr = &sDeriveObj;
	basePtr->print();
	basePtr->fun1_virtual();
	basePtr->fun2_virtual();

}