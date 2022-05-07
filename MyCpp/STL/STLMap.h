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

class KEY {
public:
	int id;
	KEY(int i): id(i){}
	bool operator < (const KEY& a1) const {
		return (this->id >  a1.id);
	}
};

/* Key as used defined data type
*/
void Test_STLMap1() {
	std::map<KEY, int> stlMapObj;
	KEY a = { 2 };
	KEY b = { 3 };
	KEY c = { 1 };
	KEY d = { 4 };
	stlMapObj.insert(std::pair<KEY, int>(d,4));
	stlMapObj[b] = 3;
	stlMapObj[a] = 1;
	stlMapObj[c] = 2;

	for (auto itr = stlMapObj.begin(); itr != stlMapObj.end(); itr++) {
		cout << "Key : " << itr->first.id << " Value: " << itr->second << std::endl;
	}
}

/* Sort map based on value
*/

bool cmp(std::pair<KEY, int>& lhs, std::pair<KEY, int>& rhs) {
	return lhs.second < rhs.second;
}

void Test_STLMap2() {
	std::map<KEY, int> stlMapObj;
	KEY a = { 2 };
	KEY b = { 3 };
	KEY c = { 1 };
	KEY d = { 4 };
	stlMapObj.insert(std::pair<KEY, int>(d, 4));
	stlMapObj[b] = 3;
	stlMapObj[a] = 1;
	stlMapObj[c] = 2;
	std::vector<pair<KEY, int>> vec;
	for (auto& it : stlMapObj) {
		vec.push_back(it);
	}
	std::sort(vec.begin(), vec.end(), cmp);

	for (auto itr = vec.begin(); itr != vec.end(); itr++) {
		cout << "Key : " << itr->first.id << " Value: " << itr->second << std::endl;
	}

}