#pragma once
#include<iostream>
#include<queue>

void Test_STLQueue() {
	std::cout << "-------------- STL Queue ------------------ \n";
	std::queue<int> queueObj;
	queueObj.push(1);
	queueObj.push(2);
	queueObj.push(3);
	queueObj.push(4);

	std::cout << "Queue Front: " << queueObj.front() << std::endl;
	std::cout << "Queue Back: " << queueObj.back() << std::endl;
	queueObj.pop();
	std::cout << "Queue Front: " << queueObj.front() << std::endl;
	std::cout << "Queue Back: " << queueObj.back() << std::endl;
}