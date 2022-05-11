#pragma once
#include<iostream>

#define __RESIZE_VECTOR_CHUNK__ 4
template<class T>
class Vector
{
public:
	Vector();
	Vector(unsigned int);

	void push_back(const T&);
	void pop_back();
	void resize(unsigned int);

	virtual ~Vector();
private:
	T* _dArray;
	unsigned int _size;
	unsigned int _capacity;
};

