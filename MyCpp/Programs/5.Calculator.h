#pragma once
#include <iostream>
using namespace std;

void Calculator() {
	float num1, num2;
	float result{};
	char op;
	bool exit = false;
	cout << "enter the first number\n";
	cin >> num1;
	cout << "For Addition '+', Substraction '-'. Mltiplication '*', Division '/' and For exit enter X:\n";
	cout << num1;

	while (cin >> op) {

		if (result == 0) {
			result = num1;
		}
		switch (op)
		{
		case '+':
			cin >> num2;
			cout << result << "+" << num2 << "=";
			result += num2;
			cout << result << endl;
			
			break;

		case '-':
			cin >> num2;
			cout << result << "-" << num2 << "=";
			result -= num2;
			cout << result << endl;
			break;

		case '*':
			cin >> num2;
			cout << result << "*" << num2 << "=";
			result *= num2;
			cout << result << endl;
			break;

		case '/':
			cin >> num2;
			cout << result << "/" << num2 << "=";
			result /= num2;
			cout << result << endl;
			break;

		case 'X':
			exit = true;
			break;

		default:
			break;
		}
		if (exit) {
			break;
		}
		cout << result;
	}
	cout << "Exiting Calculator\n";
}