#pragma once
#include<iostream>

void Test_Pair() {
	std::pair<int, int> pair1, pair3;
	std::pair<int, std::string> pair2;

	pair1 = std::make_pair(1, 2);
	pair3 = std::make_pair(2, 4);
	pair2 = std::make_pair(5, "MD");

	std::cout << "pair1.first:" << pair1.first << std::endl;
	std::cout << "pair1.second:" << pair1.second << std::endl;
	std::cout << "pair2.first:" << pair2.first << std::endl;
	std::cout << "pair2.second:" << pair2.second << std::endl;
	std::cout << "pair3.first:" << pair3.first << std::endl;
	std::cout << "pair3.second:" << pair3.second<< std::endl;

	if (pair1 == pair3) {
		std::cout << "Pair1 and Pair3 are same\n";
	}
	else {
		std::cout << "Pair1 and Pair3 are not same\n";
	}

	pair3 = std::make_pair(1, 2);
	if (pair1 == pair3) {
		std::cout << "Pair1 and Pair3 are same\n";
	}
	else {
		std::cout << "Pair1 and Pair3 are not same\n";
	}
}