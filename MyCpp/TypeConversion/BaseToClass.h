#pragma once

#include<iostream>

class BaseToClass {
	int i;
public:
	BaseToClass(){}
	BaseToClass(int val) {
		i = val;
	}
	int getVal() {
		return i;
	}
};
void Test_BasseToClassConversion() {
	std::cout << "----------------- BasaeToClass --------------------\n";
	int x = 10;
	BaseToClass btcObj;
	btcObj = x;
	std::cout << "btcObj.getVal(): " << btcObj.getVal() << std::endl;
}