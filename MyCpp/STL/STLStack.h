#pragma once
#include<iostream>
#include <stack>

void Test_STLStack() {
	std::cout << "------------------- STL Stack -----------------------\n";

	std::stack<int> stackObj;
	stackObj.push(1);
	stackObj.push(2);
	stackObj.push(3);

	std::cout << "Stack Top:" << stackObj.top() << std::endl;
	stackObj.pop();
	std::cout << "Stack Top:" << stackObj.top() << std::endl;

}
