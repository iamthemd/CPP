#pragma once
class BaseClass {
public:
	BaseClass();
	virtual void print();
};

class DerivedClass : public BaseClass {
public:
	DerivedClass();
	void print();
};

void Test_VirtualConcept();

