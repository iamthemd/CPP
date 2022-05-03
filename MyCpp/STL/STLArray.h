#pragma once
#include<array>
#include <iostream>

/* std::array<T, size_t> : It is Fixed size sequence containter. it holds fixed size in linear	sequence.
* - It can't grow or shrink.
* - Zero sized array is valid, but it should not be dereferenced.
*/

void Test_STLArray() {
	// std::array<int, 0> zeroSized_array;
	// std::cout << "ZeroSized array dereferenced: " << *(zeroSized_array.begin()) << std::endl;
	// wwe can assign during declaration as well
	std::array<int, 10> stl_array;  //std::array<int, 2> stl_array = {1,2} (initialize with bracketc++ 17)
	for (int i = 0; i < 7; i++) {
		stl_array[i] = i + 1;
	}

	std::cout << "Accessing element 6 : " << stl_array[6] << std::endl;
	std::cout << "Accessing element using at : " << stl_array.at(6) << std::endl;
	for (auto itr = stl_array.begin(); itr != stl_array.end(); itr++) {
		std::cout << *itr << std::endl;
	}

	for (auto itr = stl_array.rbegin(); itr != stl_array.rend(); itr++) {
		std::cout << itr[0] << std::endl;
	}

	std::cout << "Front: " << stl_array.front() << std::endl;
	std::cout << "Back: " << stl_array.back() << std::endl;
	std::cout << "Size: " << stl_array.size() << std::endl;
	std::cout << "Max_Size: " << stl_array.max_size() << std::endl;
	int i = 1;
	for (auto itr = stl_array.begin(); itr != stl_array.end(); itr++) {
		*itr = i++ * 2;
	}

	for (auto itr = stl_array.begin(); itr != stl_array.end(); itr++) {
		std::cout << *itr << std::endl;
	}

	std::array<int, 10> swap_array{3,3,3,3,3,3,3,3,3,3};
	swap_array.fill(4); // it fill 4 for every element
	stl_array.swap(swap_array);
	for (auto itr = stl_array.begin(); itr != stl_array.end(); itr++) {
		std::cout << *itr << std::endl;
	}

	std::cout << "Swap_Array.size:" << swap_array.size() << std::endl;
	std::cout << "Swap_Array.maxSize: " << swap_array.max_size() << std::endl;
}

void Test_STLArray1() {
	std::array<int, 5> STL_array;
	STL_array.fill(0);
	for(int i=0; i<5; i++){
		std::cout << STL_array[i] << " ";
	}
	std::cout << std::endl;
	unsigned int item, count = 0;

	while (1) {
		std::cout << "Implementation of STL Array\n";
		std::cout << "0. Size of an Array\n";
		std::cout << "1. Insert element\n";
		std::cout << "2. Front element of array\n";
		std::cout << "3. Back element of array\n";
		std::cout << "4. Display element of array\n";
		std::cout << "5. Exit\n";
		cin >> item;
		switch (item) {
		case 0:
			std::cout << "Size of an Array: " << STL_array.size() << std::endl;
			break;
		case 1:
			std::cout << "Enter the element\n";
			if (count >= STL_array.size()) {
				std::cout << "Array is full\n";
				break;
			}
			int element;
			cin >> element;
			STL_array.at(count++) = element;
			break;
		case 2:
			std::cout << "Front element of an Array: " << STL_array.front()<< std::endl;
			break;
		case 3:
			std::cout << "Back element of an Array: " << STL_array.back()<< std::endl;
			break;
		case 4:
			for (auto itr = STL_array.begin(); itr != STL_array.end(); itr++) {
				cout << " " << *itr;
			}
			break;
		case 5:
			exit(1);
			break;
		default:
			std::cout << "Wrong choice\n";
		}
	}

}

