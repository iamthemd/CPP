#pragma once
#include<iostream>
using namespace std;

void CheckNumIsOddOrEven() {
	int num;
	cout << "Enter the number you want to check\n";
	cin >> num;

	// Single line using ternary
	// (num % 2 == 0) ? cout << num<< " is Even." :  cout << num << " is Odd.";

	if (num % 2 == 0) {
		cout << "Number " << num << " is Even.\n";
	}
	else {
		cout << "Number " << num << " is Odd.\n";
	}
}

void CheckCharIsVowelOrConsonant() {
	char ch;
	cout << "Enter the character you want to check\n";
	cin >> ch;

	// Single line using ternary
	// (num % 2 == 0) ? cout << num<< " is Even." :  cout << num << " is Odd.";

	if (ch == 'A' || ch == 'a' || ch == 'E' || ch == 'e' || ch == 'I' || ch == 'i'
		|| ch == 'O' || ch == 'o' || ch == 'U' || ch == 'u') {
		cout << "Character " << ch << " is Vowel.\n";
	}
	else {
		cout << "Character " << ch << " is Consonant.\n";
	}
}
