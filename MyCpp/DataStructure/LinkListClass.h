#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

template <class T>
class LinkListClass
{
public:
	LinkListClass();
	struct Iterator
	{
		Iterator(T* rhs):m_ptr(rhs){}
		T* operator -> () {
			return m_ptr;
		}

		T& operator* () {
			return *m_ptr;
		}

		Iterator& operator ++() {
			m_ptr = m_ptr->nextPtr;
			return *this;
		}

		Iterator& operator ++(int) {
			m_ptr = m_ptr->nextPtr;
			return *this;
		}

		friend bool operator == (const Iterator& lhs, const Iterator& rhs) {
			return lhs.m_ptr == rhs.m_ptr;
		}

		friend bool operator != (const Iterator& lhs, const Iterator& rhs) {
			return lhs.m_ptr != rhs.m_ptr;
		}
		private:
			T* m_ptr;
	};

	Iterator begin() {
		return Iterator(headPtr);
	}

	Iterator end() {
		return Iterator(backPtr->nextPtr);
	}

	void push_back(const T&);
	void push_front(const T&);
	void insert(Iterator&, const T&);
	void printList();

	//void insertAtBegin(int val);
	//void insertAtMiddle(int pos, int val);
	//void insertAtEnd(int val);

	//void deleteNodeByVal(int);
	//void deleteNodeByNo(int);

	int getSizeofLinkList();
	//void printList();
	//void printList(T* ptr);
	//void printListReverse(T* ptr);
	//T* getHeadPtr() {
	//	return headPtr;
	//}
private:
	int _count;
	T* headPtr;
	T* backPtr;
};

void Test_SingleLinkList();