#pragma once
#include<iostream>

using namespace std;

void SumofNaturalNumber() {
	int n, sum = 0;
	cout << "Enter the number for getting the sum of Natural number\n";
	cin >> n;
	if (n < 0) {
		cout << "Enter the valid natural number \n";
		cout << "Fuck you!";
		return;
	}
	for (int i = 1; i <= n; i++) {
		sum += i;
	}
	cout << "Sum of " << n << " Natural number is " << sum << endl;
}