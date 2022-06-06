#pragma once
#include <iostream>

namespace Inheritance{

class Base{
public:
	Base();
	~Base();

private:
	void foo() { std::cout << "Private Method of Base::foo()\n"; }
};

class Derive {
public:
	Derive();
	~Derive();
private:
	void foo1() { std::cout << "Private Method of Derive::foo1()\n"; }
};

class Single : public Base {	// Single Inheritance 
public:
	Single();
	~Single();
};

class Multilevel : public Single { // Multilevel inheritance 
public:
	Multilevel();
	~Multilevel();
};

class Multiple : public Base, public Derive {
public:
	Multiple();
	~Multiple();
};

class Single1 : public Base {
public:
	Single1();
	~Single1();
};

class Hybrid : public Single, public Single1{
public:
	Hybrid();
	~Hybrid();
};
}

void Test_Inheritnce();

