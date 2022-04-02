#pragma once
#include<iostream>
using namespace std;
void GenerateMultiplicationTable() {
	int tableNum, range = 10;
	cout << "Enter the table number\n";
	cin >> tableNum;
	cin >> range;
	for (int i = 1; i <= range; i++) {
		cout << tableNum << " * " << i << " = " << tableNum * i << endl;
	}
 }
