#pragma once
#include <iostream>

template<typename T>
class SharedPtr
{
	T* m_ptr;
	int* refCount;
public:
	SharedPtr(T* ptr = nullptr) {
		if (ptr) {
			refCount = new int(1);
		}
		else {
			refCount = nullptr;
		}
	}

	~SharedPtr() {
		if (m_ptr != nullptr) {
			(*refCount)--;
			if (*refCount == 0) {
				delete m_ptr;
				delete refCount;
			}
		}
	}
	//copy constructor
	SharedPtr(const SharedPtr& rhs) {
		m_ptr = rhs.m_ptr;
		refCount = rhs.refCount;
		(*refCount)++;
	}

	// copy assignment
	SharedPtr& operator = (const SharedPtr& rhs) {
		m_ptr = rhs.m_ptr;
		refCount = rhs.refCount;
		(*refCount)++;
		return *this;
	}

	// Move Constructor
	SharedPtr(SharedPtr&& rhs) {
		m_ptr = rhs.m_ptr;
		refCount = rhs.refCount;
		rhs.m_ptr = nullptr;
		refCount = nullptr;
	}
	// Move Assignement
	SharedPtr& operator = (SharedPtr&& rhs) {
		if (this == &rhs) {
			return *this;
		}
		else {
			delete m_ptr;
			delete refCount;
			m_ptr = rhs.m_ptr;
			rhs.m_ptr = nullptr;
			refCount = rhs.refCount;
			rhs.refCount = nullptr;
			return *this;
		}
	}

	T& operator *() {
		return *m_ptr;
	}

	T* operator->() {
		return m_ptr;
	}
};

class Resource {
public:
	Resource() {
		std::cout << "Resource Acquired\n";
	}

	~Resource() {
		std::cout << "Resource Destroyed\n";
	}
};

SharedPtr<Resource> func(SharedPtr<Resource> temp) {
	return temp;
}
void Test_SharedPtr() {
	Resource* ptr = new Resource();
	SharedPtr<Resource> sharedPtrObj(ptr);
	{
		SharedPtr<Resource>  ptr1(sharedPtrObj);
		auto ptr2 = func(ptr1);
		std::cout << "----------- End of block--------------\n";
	}
	std::cout << "----------- End of main --------------\n";
}