#pragma once
#include<iostream>

# define MAX_SIZE 24
template <typename T>
class QueueThroughStack {
	T m_stack1[MAX_SIZE];
	T m_stack2[MAX_SIZE];
	T m_queue[MAX_SIZE];

	void push(T);
	void pop();
	T top();
	bool stack1empty() {
		return sizeStack1 == -1;
	}

	bool stack2empty() {
		return sizeStack2 == -1;
	}

	int head;
	int back;
	int sizeStack1, sizeStack2;
public:
	QueueThroughStack() {
		head = 0;
		back = 0;
		sizeStack1 = -1;
		sizeStack2 = -1;
	}

	void enqueue(T);
	T dequeue();
};

template<typename T>
void QueueThroughStack<T>::push(T val) {
	if(sizeStack1 < MAX_SIZE){
		m_stack1[++sizeStack1] = val;
	}
	else {
		std::cout << "Queue full\n";
	}
}

template<typename T>
void QueueThroughStack<T>::pop() {
	if (stack1empty() && stack2empty()) {
		std::cout << "Queue full\n";
	}
	if (stack2empty()) {
		while (!stack1empty()) {
			m_stack2[++sizeStack2] = m_stack1[sizeStack1--];
		}
	}
}

template<typename T>
T QueueThroughStack<T>::top() {
	if (stack2empty()) {
		return (T)NULL;
	}
	return m_stack2[sizeStack2--];
}

template<typename T>
void QueueThroughStack<T>::enqueue(T val) {
	push(val);
}

template<typename T>
T QueueThroughStack<T>::dequeue() {
	pop();
	return top();
}

void TestQueueUsingStack() {
	QueueThroughStack<std::string> m_queue;
	m_queue.enqueue("asd");
	m_queue.enqueue("dfg");
	m_queue.enqueue("ert");
	m_queue.enqueue("qwer");
	std::cout << m_queue.dequeue() << std::endl;
	std::cout << m_queue.dequeue() << std::endl;
	std::cout << m_queue.dequeue() << std::endl;
	std::cout << m_queue.dequeue() << std::endl;
}