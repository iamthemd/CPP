#pragma once
#include <iostream>

/* Function Overeride: Function override means function defined in the base class again defined in derived class.
* Prototype of function should be same and return type as well.
* Inheritance is necessary to achieve function override.
*  Function override is part of runtime polymorphism. Is is more flexible but slow in execution.
*/
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