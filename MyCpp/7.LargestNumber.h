#pragma once
#include<iostream>
using namespace std;

void FindTheLargestNumberofThree() {
	int first, second, third;
	cout << "Enter the first number\n";
	cin >> first;
	cout << "Enter the second number\n";
	cin >> second;
	cout << "Enter the third number\n";
	cin >> third;

	if (first >= second) {
		if (first >= third) {
			cout << "Largest number is " << first << endl;
		}
		else {
			cout << "Largest number is " << third << endl;
		}
	}
	else if (second >= third) {
		cout << "Largest number is " << second << endl;
	}
	else {
		cout << "Largest number is " << third << endl;
	}
}