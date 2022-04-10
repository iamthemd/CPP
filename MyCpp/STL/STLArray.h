#pragma once
#include<array>
#include <iostream>

/* std::array<T, size_t> : It is Fixed size sequence containter. it holds fixed size in linear	sequence.
* - It can't grow or shrink.
* - Zero sized array is valid, but it should not be derefereced. 
*/

void Test_STLArray() {
	// std::array<int, 0> zeroSized_array;
	// std::cout << "ZeroSized array dereferenced: " << *(zeroSized_array.begin()) << std::endl;
	std::array<int, 10> stl_array;
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
	stl_array.swap(swap_array);
	for (auto itr = stl_array.begin(); itr != stl_array.end(); itr++) {
		std::cout << *itr << std::endl;
	}
}

