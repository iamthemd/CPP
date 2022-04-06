#pragma once
namespace Inheritance{

class Base{
public:
	Base();
};

class Derive : public Base {
public:
	Derive();
};

class Derive1 : public Derive {
public:
	Derive1();
};

}

void Test_Inheritnce();

