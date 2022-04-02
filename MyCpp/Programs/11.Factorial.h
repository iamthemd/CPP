#pragma once
#include <iostream>
using namespace std;

/* Factorial of number is the product of all interger from 1 up to that number
*  Factorial for negative  number doesn't exist.
*  And the Factorial od 0 is 1.
*/
void Factorial() {
	int n, factValue = 1;
	cout << "Enter the integer nunber for factorial\n";
	cin >> n;
	if (n < 0) {
		cout << "Factorial for negative  number doesn't exist.\n";
		cout << "Enter the valid Integer number\n";
		return;
	}
	for (int i = 2; i <= n; i++) {
		factValue *= i;
	}
	cout << "Factorial value for integer " << n << " is " << factValue << endl;
}