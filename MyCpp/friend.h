#pragma once
#include<iostream>
using namespace std;

// Access private datamember of class using friend class
class Wife;
class Husband {
private:
	int salary;
	string name;

public:
	Husband() {
		salary = 0;
		name = "";
	}
	void setData() {
		cout << "Enter the name of husband\n";
		cin >> name;
		cout << "Enter the salary of husband\n";
		cin >> salary;
	}

	void printData() {
		cout << "Name of Husband: " << name << endl;
		cout << "Salary of Husband: " << salary << endl;
	}

	friend int totalSalary(Husband h, Wife w);
};


class Wife {
private:
	int salary;
	string name;

public:
	Wife() {
		salary = 0;
		name = "";
	}
	void setData() {
		cout << "Enter the name of wife\n";
		cin >> name;
		cout << "Enter the salary of wife\n";
		cin >> salary;
	}

	void printData() {
		cout << "Wife name: " << name << endl;
		cout << "Wife's salary: " << salary << endl;
	}
	friend int totalSalary(Husband h, Wife w);
};

int totalSalary(Husband h, Wife w) {
	return (h.salary + w.salary);
}
void Test_Friend() {
	Husband h;
	Wife w;
	h.setData();
	w.setData();
	cout << "total Salary: " << totalSalary(h, w) << endl;
}