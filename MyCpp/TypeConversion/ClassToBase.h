#pragma once
#include<iostream>

class ClassToBase {
	int i;
public:
	ClassToBase(int x) {
		i = x;
	}

	operator int() {
		return i;
	}
};
void Test_ClassToBase() {
	std::cout << "----------------- ClassToBase --------------------\n";
	int x;
	ClassToBase ctbObj(10);
	x = ctbObj;
	std::cout << "x:" << x << std::endl;
}
