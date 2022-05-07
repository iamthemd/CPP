#pragma once
#include <iostream>
#include <deque>

void Test_STLDequeue() {
	std::cout << "----------------- Dequeue ------------------------- \n";
	std::deque<int> dequeObj;
	dequeObj.push_back(1);
	dequeObj.push_front(0);

}