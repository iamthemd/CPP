#pragma once

typedef struct Test {
	int a;
}c;

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

