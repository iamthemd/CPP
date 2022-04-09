#pragma once

typedef struct Node {
	int val;
	Node* nextPtr;
}Node;

typedef struct DNode {
	int val;
	DNode* nextPtr;
	DNode* prevPtr;
}DNode;