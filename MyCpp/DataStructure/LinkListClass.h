#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

class LinkListClass
{
public:
	LinkListClass();

	/* This function will enter new entry in list at the end.*/
	void insertAtBegin(int val);
	void insertAtMiddle(int pos, int val);
	void insertAtEnd(int val);

	void deleteNodeByVal(int);
	void deleteNodeByNo(int);

	int getSizeofLinkList();
	void printList();
private:
	int _count;
	Node* headPtr;
};

void Test_SingleLinkList();