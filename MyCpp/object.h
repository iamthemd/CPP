#pragma once
#include <iostream>
#pragma pack(1)
/* Class: class is nothing but blueprint, who has data member and member function.
*       : It is user-defined data type.
*/
class MyFirstClass {
public:
	/* 
	* dataMember1, dataMember2: both are data member of class MyFirstClass
	*/
	int dataMember1;
	char dataMember2;

	/*
	* setMemberFunction1, setMemberFunction1
	* setMemberFunction2, setMemberFunction2: All are member function of class MyFirstClass
	*/
	void setMemberFunction1(int val) {
		dataMember1 = val;
	}

	int getMemberFunction1() {
		return dataMember1;
	}

	void setMemberFunction2(int val) {
		dataMember2 = val;
	}

	char getMemberFunction2() {
		return dataMember2;
	}
};

void TestObject() {
	/*
	* Every object have separate datamember, but member function arer common to all object.
	* Every object having separate memory.
	* Size of an object is equal to the sum of size of the data member.
	* Instane of class is called object.
	*/
	MyFirstClass obj, obj2;
	obj.setMemberFunction1(100);
	std::cout << obj.getMemberFunction1() << std::endl;
	obj.setMemberFunction2('A');
	std::cout << obj.getMemberFunction2() << std::endl;

	std::cout << "Size of class: " << sizeof(MyFirstClass) << std::endl;
	std::cout << "Size of obj: " << sizeof(obj) << std::endl;

	std::cout << "=============Address of obj ============ " << std::endl;
	std::cout << "Address of obj: " << &obj << std::endl;
	std::cout << "Address of obj.dataMember1: " << &obj.dataMember1 << std::endl;
	
	std::cout << "=============Address of obj2 ============ " << std::endl;
	std::cout << "Address of obj2: " << &obj2 << std::endl;
	std::cout << "Address of obj2.dataMember1: " << &obj2.dataMember1 << std::endl;
}