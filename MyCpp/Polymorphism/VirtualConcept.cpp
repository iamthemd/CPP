#include<iostream>

#include "VirtualConcept.h"

BaseClass::BaseClass() {
	std::cout << "In base class constructor\n";
}

void BaseClass::print() {
	std::cout << "In Base class print function\n";
}

DerivedClass::DerivedClass() {
	std::cout << "In dericed class constructor\n";
}

void DerivedClass::print() {
	std::cout << "n Derived class print function\n";
}

void Test_VirtualConcept() {
	BaseClass baseObj, *basePtr;
	DerivedClass derivedObj, * derivedPtr;
	baseObj.print();
	derivedObj.print();

	basePtr = &derivedObj;
	basePtr->print();

}