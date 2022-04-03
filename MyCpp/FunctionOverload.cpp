#include "FunctionOverload.h"

FunctionOverload::FunctionOverload() {
	value = 0;
	ch = ' ';
	f = 0.0;
	str = "";
}

void FunctionOverload::setValue(int iVal, char cVal, float fVal, std::string stVal) {
	value = iVal;
	ch = cVal;
	f = fVal;
	str = stVal;
}

void FunctionOverload::setValue(int iVal, char cVal, std::string stVal, float fVal) {
	value = iVal;
	ch = cVal;
	f = fVal;
	str = stVal;
}

void FunctionOverload::setValue(int iVal, int cVal, float fVal, std::string stVal) {
	value = iVal;
	ch = cVal;
	f = fVal;
	str = stVal;
}

void FunctionOverload::printValue() {
	std::cout << value << std::endl;
	std::cout << ch << std::endl;
	std::cout << f << std::endl;
	std::cout << str << std::endl;
}