#include <iostream>
#include "OperatorOverloading.h"

OperatorOverload::OperatorOverload(int val) {
	value = val;
}
void OperatorOverload::operator ++ () {
	++value;
}

void OperatorOverload::operator -- () {
	--value;
}

void OperatorOverload::operator ++ (int) {
	value++;
}

void OperatorOverload::operator -- (int) {
	value--;
}

OperatorOverload OperatorOverload::operator + (const OperatorOverload& obj) {
	OperatorOverload temp;
	temp.value = value + obj.value;
	return temp;
}

OperatorOverload OperatorOverload::operator - (const OperatorOverload& obj) {
	OperatorOverload temp;
	temp.value = value - obj.value;
	return temp;
}

OperatorOverload OperatorOverload::operator * (const OperatorOverload& obj) {
	OperatorOverload temp;
	temp.value = value * obj.value;
	return temp;
}

OperatorOverload OperatorOverload::operator / (const OperatorOverload& obj) {
	OperatorOverload temp;
	if (obj.value == 0) {
		std::cout << "Divided by zero error:" << std::endl;
		return temp;
	}
	temp.value = value / obj.value;
	return value;
}

bool OperatorOverload::operator < (const OperatorOverload& obj) {
	return value < obj.value;
}

bool OperatorOverload::operator > (const OperatorOverload& obj) {
	return value > obj.value;
}

bool OperatorOverload::operator == (const OperatorOverload& obj) {
	return value == obj.value;
}

bool OperatorOverload::operator != (const OperatorOverload& obj) {
	return value != obj.value;
}
void OperatorOverload::Printvalue() {
	std::cout << "Value = " << value << std::endl;
}
void Test_OperatorOveload() {
	OperatorOverload obj(10), obj2(5), result;
	std::cout << "Before preincrement" << std::endl;
	obj.Printvalue();
	++obj;
	std::cout << "Afer preincrement:"<< std::endl;
	obj.Printvalue();
	--obj;
	std::cout << "Afer predecrement:" << std::endl;
	obj.Printvalue();
	obj++;
	std::cout << "Afer postincrement:" << std::endl;
	obj.Printvalue();
	obj--;
	std::cout << "Afer postdecrement:" << std::endl;
	obj.Printvalue();

	result = obj + obj2;
	result.Printvalue();
	result = obj - obj2;
	result.Printvalue();
	
	std::cout << (obj < obj2) << std::endl;
	std::cout << (obj > obj2) << std::endl;
	std::cout << (obj == obj2) << std::endl;
	std::cout << (obj != obj2) << std::endl;
}

