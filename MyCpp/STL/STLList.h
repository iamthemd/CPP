#pragma once
#include<iostream>
#include<list>

/* Array and vector are contiguous contianer, they store data in contiguous location (memory), thus
*  the inserting element at the middle operation is very costly in terms of operation and process time.
*  because we have to shift all the element, linked list overcome this problem.
*/
static void emplance_back_test();
void Test_STLList() {
	std::cout << "--------------- STL List ----------------------------\n";
	std::list<int> listObj{ 1,5,4,3,2};
	std::list<int>::iterator itr = listObj.begin();

	for (itr; itr != listObj.end(); itr++) {
		std::cout << *itr << " ";
	}
	std::cout << "\n";

	std::cout << "--------------- push_back and push_front----------------------------\n";
	listObj.push_back(6);
	listObj.push_front(0);

	for (itr = listObj.begin(); itr != listObj.end(); itr++) {
		std::cout << *itr << " ";
	}
	std::cout << "\n";

	std::cout << "--------------- pop_back and pop_front----------------------------\n";
	listObj.pop_back();
	listObj.pop_front();
	for (itr = listObj.begin(); itr != listObj.end(); itr++) {
		std::cout << *itr << " ";
	}
	std::cout << "\n";

	std::cout << "--------------- reverse the list ----------------------------\n";
	listObj.reverse();
	for (itr = listObj.begin(); itr != listObj.end(); itr++) {
		std::cout << *itr << " ";
	}
	std::cout << "\n";

	std::cout << "---------------  Splice ------------------------------  \n";
	std::list<int> secondList = { 6,9,8,10,7 };
	itr = listObj.begin();
	itr++;
	listObj.splice(itr, secondList);
	for (itr = listObj.begin(); itr != listObj.end(); itr++) {
		std::cout << *itr << " ";
	}
	std::cout << "\n";

	std::cout << "---------------  Sort ------------------------------  \n";
	listObj.sort();
	secondList.sort();
	for (itr = listObj.begin(); itr != listObj.end(); itr++) {
		std::cout << *itr << " ";
	}
	for (itr = secondList.begin(); itr != secondList.end(); itr++) {
		std::cout << *itr << " ";
	}
	std::cout << "\n";

	std::cout << "--------------- Merge ------------------------------ \n";
	listObj.merge(secondList);
	for (itr = listObj.begin(); itr != listObj.end(); itr++) {
		std::cout << *itr << " ";
	}

	std::cout << "--------------- Emplance_back ------------------------------ \n";
	emplance_back_test();
}

class MyClassList {
public:
	MyClassList(int x, int y) :_x(x), _y(y) {
		std::cout << "In My class Construtor\n";
	}

	~MyClassList() {
		std::cout << "In MyClass Destructor\n";
	}
	
	// Copy Constructor
	MyClassList(const MyClassList& obj) {
		std::cout << "Copy onstructor Called\n";
		_x = obj._x;
		_y = obj._y;
	}

	// Move Constructor
	MyClassList(const MyClassList&& obj) {
		std::cout << "Move Constructor Called\n";
		_x = obj._x;
		_y = obj._y;
	}
private:
	int _x;
	int _y;
};
/* push_back: Adds the new element at the end of te container, after its current last element.
 *            Content of the val is copied(or moved) to the new element.
 * emplace_back: insert a new element at the end of the container, after its current last element.
 *            This neew element is constructed in place using args as the argument for constructor.
 * 
 * What will happen if we call push_back ?
 * 1. Constructor will be called to create temporary object.
 * 2. A copy of temporary object constructed in memory for the container. Note that move contrutor will be called
 *    if exist because temporary object is an rvalue, otherwise copy construtor should be called.
 * 3. The destructor will be called to destroy the temporary object after copy.
*/
static void emplance_back_test() {
	std::list<MyClassList> myClassList;
	myClassList.push_back(MyClassList(1, 2));

	/* Here wew can see push_back method calls the move construtor to make copy and destructor to destroy
	*  temporary object, but emplace_back directly construct object.
	*/
	myClassList.emplace_back(3, 4);
}

/* Why not use emplace_back all the time ?
* std::vector<std::vector<int>> vec1,vec2;
* vec1.pus_back(1000000); // ======== Compile Error
* vec1.emplace_back(1000000);
* std::cout << "Vector Size " << vec1.at[0].size() << std::endl;
* output : vector Size 1000000
* Above example it construct a vector of 1000000 element and allocating memory in the process,
* it is unexpected and it takes longer time to catch this problem.
*/