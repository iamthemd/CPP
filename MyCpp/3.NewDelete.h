#pragma once
#include<iostream>

/* new and delete: 
*	- Both are operator not a function.
*	- new and delete is useful for allocating dynamically memory and freeing the allocated memory respective.
*	- dynamic memory allocation is technique when it is not known in advanced howmuch of memory space needed
*	  and we can allocate memory it runtime.
*  Syntx:new -> pointer_variable = new data_type;
*        delete -> delete pointer_variable;
*	- new operater compute the size of oject automatically, it return the correct pointer type automatically.
*/

class NewDeleteClass {
public:
	int a;
	int b;
	float f;
};

void Test_NewDelete() {
	// It allocates the size of int and assign value to 10 at the address where it allocated memory.
	int* ptr = new int(10);
	std::cout << "ptr:" << ptr << " value ptr holding:" << *ptr << " size of ptr:" << sizeof(ptr) << "\n";
	// delete or free the allocated memory.
	delete ptr;
	
	// It allocate the 10 * sizeof int. it allocates array of 10 int.
	int* ptr1 = new int[10];
	std::cout << "ptr:" << ptr1 << " size of ptr:" << sizeof(ptr1) << "\n";
	for (int i = 0; i < 10; i++) {
		ptr1[i] = (i+1) * 10;
	}

	for (int i = 0; i < 10; i++) {
		std::cout << "ptr[" << i << "]:" << ptr1[i] << "\n";
	}

	// It free the allocated array
	delete [] ptr1;

	NewDeleteClass* ptrclass = new NewDeleteClass();
	ptrclass->a = 123;
	ptrclass->b = 456;
	ptrclass->f = 1234.5;
	// size of class you will get 4 0r 8 based on your system, if it is 32 bit it gives you 4 or else 8 for 64 bit OS.
	// Here you would be wonder why it is giving size 4 0r 8 rathere sum of all datamember, because it is giving the size of 
	// pointer not the howmuch memory it allocated.
	std::cout << "size of ptrclass:" << sizeof(ptrclass) << "\n";
	std::cout << "ptrclass->a: " << ptrclass->a << "\n";
	std::cout << "ptrclass->b: " << ptrclass->b << "\n";
	std::cout << "ptrclass->f: " << ptrclass->f << "\n";

	// Here you will see pointer address and when memory allocated both are different.
	std::cout << "address of ptrClass :" << &ptrclass << "\naddress of ptrClass->a :" << &(ptrclass->a)
		<< "\naddress of ptrClass->b :" << &(ptrclass->b) <<
		"\naddress of ptrClass->f :" << &(ptrclass->f) << "\n";
}
