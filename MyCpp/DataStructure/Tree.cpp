#include "Tree.h"

Tree::Tree() {
	m_root = nullptr;
}

void Tree::insertNode(int val) {
	TNode<int>* ptr = new TNode<int>();
	ptr->left = nullptr;
	ptr->right = nullptr;
	ptr->val = val;

	if (m_root == nullptr) {
		m_root = ptr;
	}
	else {
		TNode<int>* temp = m_root;
		TNode<int>* parent = nullptr;
		while (temp != nullptr) {
			parent = temp;
			if (val < temp->val) {
				temp = temp->left;
			}
			else {
				temp = temp->right;
			}
		}
		if (val < parent->val) {
			parent->left = ptr;
		}
		else {
			parent->right = ptr;
		}
	}
}

void Tree::printInOrder(TNode<int>* ptr)
{
	if (ptr) {
		printInOrder(ptr->left);
		std::cout << ptr->val << " ";
		printInOrder(ptr->right);
	}
}

void Tree::printPreOrder(TNode<int>* ptr)
{
	if (ptr) {
		std::cout << ptr->val << " ";
		printPreOrder(ptr->left);
		printPreOrder(ptr->right);
	}
}

void Tree::printPostOrder(TNode<int>* ptr)
{
	if (ptr) {
		printPostOrder(ptr->left);
		printPostOrder(ptr->right);
		std::cout << ptr->val << " ";
	}
}

void Test_Tree() {
	Tree t;
	t.insertNode(37);
	t.insertNode(27);
	t.insertNode(47);
	t.insertNode(22);
	t.insertNode(32);
	t.insertNode(12);
	t.insertNode(25);
	t.insertNode(42);
	t.insertNode(57);
	t.insertNode(52);
	t.insertNode(67);

	std::cout << "------------- In Order ----------------\n";
	t.printInOrder(t.getRootPtr());
	std::cout << "------------- Pre Order ----------------\n";
	t.printPreOrder(t.getRootPtr());
	std::cout << "------------- Post Order ----------------\n";
	t.printPostOrder(t.getRootPtr());
}