#pragma once

class Test {
public:
	int a;
	Test();
	~Test();
};

template <typename T>
class SmartPtr
{
public:
	SmartPtr(T* ptr = nullptr);
	~SmartPtr();

	T& operator *();
	T* operator ->();
private:
	T* _ptr;
};

void Test_SmartPointer();

