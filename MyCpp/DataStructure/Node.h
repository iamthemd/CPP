#pragma once

typedef struct Node {
	unsigned int val;
	Node* nextPtr;
}Node;

typedef struct DNode {
	unsigned int val;
	DNode* nextPtr;
	DNode* prevPtr;
}DNode;
