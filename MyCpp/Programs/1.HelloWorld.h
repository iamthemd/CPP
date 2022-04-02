#pragma once
#include<iostream>

using namespace std;

void HelloWorld() {
	cout << "Hello World!\n" << endl;

	cout << "sieof(char):" << sizeof(char) << std::endl;
	cout << "sieof(wchar_t):" << sizeof(wchar_t) << std::endl;
	cout << "sieof(short):" << sizeof(short) << std::endl;
	cout << "sieof(int):" << sizeof(int) << std::endl;
	cout << "sieof(float):" << sizeof(float) << std::endl;
	cout << "sieof(double):" << sizeof(double) << std::endl;
	cout << "sieof(long double):" << sizeof(long double) << std::endl;
}