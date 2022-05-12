#pragma once
#include<iostream>

#define __RESIZE_VECTOR_CHUNK__ 4

template<class T>
class Vector
{
public:

	struct Iterator {
		Iterator(T* ptr):m_ptr(ptr){}

		// implement operator
		T& operator *() {
			return *m_ptr;
		}

		T* operator ->() {
			return m_ptr;
		}

		// Prefix increment
		Iterator& operator ++() {
			m_ptr++;
			return *this;
		}

		// Postfix increment
		Iterator& operator ++(int) {
			++m_ptr;
			return *this;
		}

		friend bool operator == (const Iterator& lhs, const Iterator& rhs) {
			return lhs.m_ptr == rhs.m_ptr;
		}

		friend bool operator != (const Iterator& lhs, const Iterator& rhs) {
			return lhs.m_ptr != rhs.m_ptr;
		}

		Iterator erase(Iterator position) {

		}
	private:
		T* m_ptr;
	};

	Vector();
	Vector(unsigned int);

	Iterator begin() {
		return Iterator(&_dArray[0]);
	}

	Iterator end() {
		return Iterator(&_dArray[_size]);
	}

	void push_back(const T&);
	void pop_back();
	void resize(unsigned int);
	virtual ~Vector();
private:
	T* _dArray;
	unsigned int _size;
	unsigned int _capacity;
};

void Test_Vector();

