#pragma once
#include "Node.h"

class DoubleLinkList
{
public:
	DoubleLinkList();
	void insertAtBegin(int);
	void insertAtEnd(int);
	void insertAtMiddle(int, int);

	void deleteNodeByPos(int);
	void deleteNodeByVal(int);
	void printList();
	int getSizeOfList();

private:

	int _count;
	DNode* _headPtr;;
};

void Test_DoubleLinkList();

