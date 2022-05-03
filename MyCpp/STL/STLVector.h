#pragma once
#include<iostream>
#include <vector>
#include <algorithm>

/*- Just like Array vector is also a contigous storage location for their element. So element also can be access using offset.
* - vector size can change dynamically. it is not like array.
* - Vector used dynamically array to allocate its element, It may needs to reallocate in order to grow in size when element inserted.
* - Mean when new element inserted it require to move all element.this is extensive task in terms of processing time.
* - That's why vecor container allocate extra storage to accomodate possible grow.
* - compare to array vector consume more memory.
*/

/*
* 1. In vector all element remain same order in which they are inserted.
* 2. Indexing is very fast in vector using []operator.
* 3. It perform better in insertion/deletion at the end and gives worst performance at the middle or start.
* 4. It always stores the copy of object not the same reference. So if we are adding object of 
     user define class then we should define copy constructor and assignment operator overload.
* why use vector? : std::vector gives same kind of performance in indexing and iteration as arrays.
* But it don't have limitation like arrays. We no need to provide fixed size for vector in advanced.
* It will automatically expande the size.
*/
void Test_STLVector() {
	std::vector<int> vector_Obj(8);
	std::cout << "Capacity: " << vector_Obj.capacity() << std::endl;
	std::cout << "Size: " << vector_Obj.size() << std::endl;
	
	vector_Obj.push_back(1);
	vector_Obj.push_back(2);
	vector_Obj.push_back(3);
	vector_Obj.push_back(4);

	vector_Obj.push_back(5);
	
	vector_Obj.push_back(6);
	vector_Obj.push_back(7);
	vector_Obj.push_back(8);

	std::cout << "---------------- Vector Element print ----------------\n";

	for (auto itr = vector_Obj.begin(); itr != vector_Obj.end(); itr++) {
		std::cout << *itr << std::endl;
	}

	std::cout << "---------------- Vector Element print in reverse order ----------------\n";
	for (auto itr = vector_Obj.rbegin(); itr != vector_Obj.rend(); itr++) {
		std::cout << *itr << std::endl;
	}

	std::cout << "--------------- Resizing vector ---------------------\n";
	vector_Obj.resize(14);
	vector_Obj.shrink_to_fit();

	std::cout << "---------------- Vector Properties ----------------\n";
	std::cout << "Capacity: " << vector_Obj.capacity() << std::endl;
	std::cout << "Size: " << vector_Obj.size() << std::endl;

	vector_Obj.pop_back();
	std::cout << "---------------- Vector After pop_back----------------\n";
	std::cout << "Capacity: " << vector_Obj.capacity() << std::endl;
	std::cout << "Size: " << vector_Obj.size() << std::endl;

	std::vector<int> vector2(vector_Obj.begin(), vector_Obj.end());
	for (auto itr = vector2.begin(); itr != vector2.end(); itr++) {
		std::cout << *itr << std::endl;
	}

	std::vector<int> vector3(10, 3);
	for (auto itr = vector3.begin(); itr != vector3.end(); itr++) {
		std::cout << *itr << std::endl;
	}
}

void Test_STLVector1() {
	std::cout << "STL vector \n";
	std::vector<std::string> strVector;
	strVector.push_back("Hey");
	strVector.push_back("I");
	strVector.push_back("Am");
	strVector.push_back("The");
	strVector.push_back("MD!");

	for (auto itr = strVector.begin(); itr != strVector.end(); itr++) {
		std::cout << *itr << " ";
	}
	std::cout << "\n";

	sort(strVector.begin(), strVector.end());
	std::cout << "After Sorting Vector\n";
	for (auto itr = strVector.begin(); itr != strVector.end(); itr++) {
		std::cout << *itr << " ";
	}

	strVector.insert(strVector.begin(), 2, "Ha ");
	std::cout << "After inserting element at begin in Vector\n";
	for (auto itr = strVector.begin(); itr != strVector.end(); itr++) {
		std::cout << *itr << " ";
	}
	
	strVector.erase(strVector.begin());
	std::cout << "After Removing first element from the	Vector\n";
	for (auto itr = strVector.begin(); itr != strVector.end(); itr++) {
		std::cout << *itr << " ";
	}

	strVector.clear();
	std::cout << "After Clearing the Vector\n";
	for (auto itr = strVector.begin(); itr != strVector.end(); itr++) {
		std::cout << *itr << " ";
	}
	std::cout << "------------------- End ------------------- \n";
}
