#pragma once
#include<iostream>
#include<map>
#include<string>

/* Map are used to replicate associative array.
*  Map contain sorted key-value pair, in which key is unique and can not be changed and it can be inserted
*  or deleted but can not be altered.value associte with key can be altered.
*  We can search, remove, insert element within mao in O(n) time complexity.
*/
void Test_STLMap() {
	std::map<int, std::string> map_IS;
	map_IS[1] = "I";
	map_IS[3] = "ME";

	std::cout << "----------------- Print the Map key value -----------------\n";
	for (auto itr = map_IS.begin(); itr != map_IS.end(); itr++) {
		std::cout << "Key: " << itr->first << " Value: " << itr->second << "\n";
	}
	std::cout << "\n";

	std::cout << "----------------- Change the value of Map -----------------\n";
	map_IS.at(1) = "HE";
	map_IS[3] = "SHE";
	std::cout << map_IS[1] << "\n";
	std::cout << map_IS[3] << "\n";

	std::cout << "----------------- Insert entry in map -----------------\n";
	map_IS.insert(std::pair<int, std::string>(0, "I"));
	map_IS.insert(std::make_pair<int, std::string>(2, "ME"));
	for (auto itr = map_IS.begin(); itr != map_IS.end(); itr++) {
		std::cout << "Key: " << itr->first << " Value: " << itr->second << "\n";
	}
	std::cout << "\n";

	std::cout << "------------------ Find key in map ---------------------\n";
	auto findPtr = map_IS.find(1);
	cout << findPtr->first << " " << findPtr->second << "\n";

	std::cout << "------------------ insert_or_assign ---------------------\n";
	map_IS.insert_or_assign(0, "YOU");
	for (auto itr = map_IS.begin(); itr != map_IS.end(); itr++) {
		std::cout << "Key: " << itr->first << " Value: " << itr->second << "\n";
	}
	std::cout << "\n";
}