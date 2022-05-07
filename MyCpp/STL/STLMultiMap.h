#pragma once
#include<iostream>
#include<map>

void Test_STLMultimap() {
	std::multimap<int, int> STLMultimapObj;
	STLMultimapObj.insert(std::pair<int, int>(0,0));
	STLMultimapObj.insert(std::pair<int, int>(0, 1));
	STLMultimapObj.insert(std::pair<int, int>(0, 2));
	STLMultimapObj.insert(std::pair<int, int>(0, 3));

	STLMultimapObj.insert(std::pair<int, int>(1, 1));
	STLMultimapObj.insert(std::pair<int, int>(1, 2));
	STLMultimapObj.insert(std::pair<int, int>(1, 2));
	STLMultimapObj.insert(std::pair<int, int>(1, 3));
	STLMultimapObj.insert(std::pair<int, int>(2, 3));
	STLMultimapObj.insert(std::pair<int, int>(3, 3));
	STLMultimapObj.insert(std::pair<int, int>(3, 4));

	for (auto &it : STLMultimapObj) {
		std::cout << it.first << " " << it.second << std::endl;
	}

	std::cout << STLMultimapObj.lower_bound(1)->first << " " << STLMultimapObj.lower_bound(1)->second << std::endl;
	std::cout << STLMultimapObj.upper_bound(1)->first << " " << STLMultimapObj.upper_bound(1)->second << std::endl;
	std::cout << STLMultimapObj.lower_bound(2)->first << " " << STLMultimapObj.lower_bound(2)->second << std::endl;
}
