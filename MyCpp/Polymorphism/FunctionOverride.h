#pragma once
#include <iostream>

class Base {
public:
	Base();
	void printString();
private:

};

class Derived: public Base {
public:
	Derived();
	void printString();
private:
};

void Test_FunctionOverride();