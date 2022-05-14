#pragma once
#include <iostream>

class BitClass {
	int m_val;
	unsigned int size = sizeof(int) * 8;
	unsigned int bitArr[sizeof(int) * 8 - 1];
public:
	BitClass() { m_val = 0; }
	BitClass(int val):m_val(val){}
	~BitClass(){}
	void convertToBit() {
		int tempVal = m_val;
		for (int i = 0; i < size; i++) {
			int oneOrZero = tempVal & 1;
			bitArr[size - i - 1] = oneOrZero;
			tempVal = tempVal >> 1;
		}
	}

	void printBits() {
		for (int i = 0; i < size; i++) {
			std::cout << bitArr[i] << " ";
		}
		std::cout << std::endl;
	}

};
void Test_Bit() {
	BitClass bitObj(10);
	bitObj.convertToBit();
	bitObj.printBits();
}
