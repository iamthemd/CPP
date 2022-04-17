#pragma once
#include<iostream>

class ClassB;
class ClassA
{
	std::shared_ptr<ClassB> b_sharedPtr;
public:
	ClassA();
	void setSharedPtr(std::shared_ptr<ClassB>& bPtr);
	~ClassA();
};

class ClassB {
	std::shared_ptr<ClassA> a_sharedPtr;
public:
	ClassB();
	void setSharedPtr(std::shared_ptr<ClassA>& bPtr);
	~ClassB();
};

void Test_SharedPtrCyclicDependancy();

