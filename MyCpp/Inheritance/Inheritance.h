#pragma once
namespace Inheritance{

class Base{
public:
	Base();
	~Base();
};

class Derive : public Base {
public:
	Derive();
	~Derive();
};

class Derive1 : public Derive {
public:
	Derive1();
	~Derive1();
};

}

void Test_Inheritnce();

