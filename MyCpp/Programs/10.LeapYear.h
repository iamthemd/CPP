#pragma once
#include<iostream>

using namespace std;

// Leap year is year which is perfectly divisble by 4 except century year(like 2000,1000,2200).
// Century year is leap year if it is perfectly divisble by 400
void IsLeapYear() {
	int year;
	cout << "Enter the year\n";
	cin >> year;

	if (year % 400 == 0) {
		cout << year << " is a leap year\n";
	}
	else if (year % 100 == 0) {
		cout << year << " is not a leap year\n";
	}
	else if (year % 4 == 0) {
		cout << year << " is a leap year\n";
	}
	else {
		cout << year << " is not a leap year\n";
	}
}
