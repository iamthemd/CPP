#pragma once
#include<iostream>
using namespace std;

void swapNumberUsingtemp(int &x, int &y) {
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void swapNumberWithoutUsingtemp(int &x, int &y) {
	x = x + y;
	y = x - y;
	x = x - y;
}

void swapNumberSingleLine(int &x, int &y) {
	(x ^= y), (y ^= x), (x ^= y);
}
void swapNumber() {
	int x, y;
	cout << "Enter first number:\n";
	cin >> x;
	cout << "Enter second number:\n";
	cin >> y;
	cout << "first number: " << x << " Second number: " << y << endl;

	//swapNumberUsingtemp(x, y);
	//swapNumberWithoutUsingtemp(x, y);
	swapNumberSingleLine(x, y);
	cout << "After Swap operation:\n";
	cout << "first number: " << x << " Second number: " << y << endl;

}