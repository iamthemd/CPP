#pragma once
#include <iostream>
using namespace std;

void QuotientAndRemainder() {
	int dividend, divisor, quotient, remainder;
	cout << "Enter the dividend";
	cin >> dividend;
	cout << std::endl;
	cout << "Enter tehe divisor";
	cin >> divisor;

	quotient = dividend / divisor;
	remainder = dividend % divisor;

	cout << "Quotient: " << quotient << endl;
	cout << "Remainder: " << remainder << endl;
}