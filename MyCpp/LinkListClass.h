#pragma once
#include <iostream>
using namespace std;

typedef struct Node {
	int val;
	Node* nextPtr;
}Node;

class LinkListClass
{
public:
	LinkListClass();

	/* This function will enter new entry in list at the end.
	*/
	void insertAtBegin(int val);
	void insertAtMiddle(int pos, int val);
	void insertAtEnd(int val);
	int getSizeofLinkList();
	void printList();
private:
	int _count;
	Node* headPtr;
};

void Test_SingleLinkList();