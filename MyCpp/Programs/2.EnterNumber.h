#pragma once
#include <iostream>
using namespace std;

void NumberEnteByUser() {
	int num, num2;
	char c;
	cout << "Enter ther first nummber\n";
	cin >> num;
	cout << "Entered first number is " << num << endl;

	cout << "Enter the second numbe\n";
	cin >> num2;
	cout << "Emntered second number is : " << num2 << endl;

	cout << "Addition of two number is : " << num + num2 << endl;
	cout << "Multiplication of two number is : " << num * num2 << endl;
	cout << "Division of two number is : " << num / num2 << endl;

	cout << "Enter the character\n";
	cin >> c;
	cout << "ASCII value of characte : " << c << " is : " << int(c) << endl;
}