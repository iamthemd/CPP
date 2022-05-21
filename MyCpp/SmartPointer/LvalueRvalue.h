#pragma once
#include<iostream>

/* In C++ lvalue is something that points to a specific memory location.On other hand rvalue
*  is something that doesn't point anywhere. In general rvalue is temporary and short lived.
*/
void refFunction(const int& ref) {

}

void Test_LValueRValue() {

	int x = 666; // Here, 666 is the rvalue, snd x variable has specific memory location so lvalue.
	int* y = &x; 

	int& z = x;
	z++;
	std::cout << "valur of z:" <<z << std::endl;

	// int& a = 90; // Error reference can't be constant.
	refFunction(90);
}
