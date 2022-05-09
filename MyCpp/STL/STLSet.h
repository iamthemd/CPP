#pragma once
#include<iostream>
#include<set>

/* Set are type of associate container in which each element has to be unique bacuase the value
*  of element identifies it. The value are stored in specific order.
* The set stored value in sorted order.
* All the element in set have unique values.
* The value of element can't be modified once it is added to the set. Though it is possible
* to remove and then add the modified the vlaue of element.
* Set follows the Binary search tree.
*
*/
void Test_STLSet() {
	std::cout << "----------------- STL Set --------------------- \n";
	std::set<int> stlSet;
	stlSet.insert(10);
	stlSet.insert(5);
	stlSet.insert(12);
	stlSet.insert(39);
	stlSet.insert(0);
	stlSet.insert(1);
	stlSet.insert(15);
	stlSet.insert(15);
	for (auto itr = stlSet.begin(); itr != stlSet.end(); itr++) {
		std::cout << *itr << std::endl;
	}

	std::set<int> s2(stlSet.begin(), stlSet.end());
	std::cout << "----------------- STL Set --------------------- \n";
	for (auto itr = s2.begin(); itr != s2.end(); itr++) {
		std::cout << *itr << std::endl;
	}

}