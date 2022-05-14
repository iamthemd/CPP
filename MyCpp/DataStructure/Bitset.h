#pragma once
#include<iostream>
#include<bitset>

void Test_Bitset() {
	std::bitset<6> a, b;
	std::cout << "Size of bitset a: " << sizeof(a) << std::endl;
	a.set();
	std::cout << "Before any operation\n";
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	for (int i = 0; i < 6; i++) {
		if (i % 2 == 0) {
			a[i].flip();
		}
	}
	
	std::cout << "After operation on a bitset\n";
	std::cout << a << std::endl;
	std::cout << b << std::endl;
}

