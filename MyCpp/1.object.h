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

int x = 100;

/*
* MUTABLE: mutable is keyword.
*	A class object or structure variable may be declare as constant. this making their datamember donot modifiable.
*	However a situation arise where we want to create a constant object but we would like to modified particular
*	datameber, in such situation we can make the particular data item modifiable by declaring the item as mutable.
*/
struct A {
	mutable int intA; // we can modify the intA eventhough object is being taken as constant.
	char charA;
};

namespace one {
	int var = 123;
}

namespace two {
	int var = 456;
}

void namespaceFun() {
	int var = 1;
	std::cout << one::var << std::endl;
	std::cout << two::var << std::endl;
	std::cout << var << std::endl;
}

void mutableFun() {
	const struct A a1 = { 10, 'a' };
	std::cout << "structure a1.intA: " << a1.intA << " a1.charA: " << a1.charA << std::endl;
	//if intA variaable of structure is not mutable then we are not allowed to change the constant val.
	// below statement only valid if intA member of structure is mutable.
	a1.intA = 23;
	std::cout << "After changing mutable intA valule of intA is "<< std::endl;
	std::cout << "structure a1.intA: " << a1.intA << " a1.charA: " << a1.charA << std::endl;
}

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

	std::cout << "========================= Address of obj ========================" << std::endl;
	std::cout << "Address of obj: " << &obj << std::endl;
	std::cout << "Address of obj.dataMember1: " << &obj.dataMember1 << std::endl;
	
	std::cout << "=============Address of obj2 ============ " << std::endl;
	std::cout << "Address of obj2: " << &obj2 << std::endl;
	std::cout << "Address of obj2.dataMember1: " << &obj2.dataMember1 << std::endl;

	std::cout << "========================= BOOL, STRING, WCHAR_T ======================== " << std::endl;
	/*
	* bool, string,wchar_t(wide character)
	*/
	bool b = true; // It represent 1
	bool c = false; // It represent 0
	std::cout << "value of bool b:" << b << std::endl;
	std::cout << "value of bool c:" << c << std::endl;

	wchar_t w = 'a';
	std::cout << w << std::endl;

	std::string s1 = "MyName";
	std::string s2 = "MySurname";
	std::cout << s1 + s2 << std::endl;
	std::cout << s1.append(s2) << std::endl;

	std::cout << "========================= ::(SCOPE RESOLUTION OPERATOR) ======================== " << std::endl;
	int x = 10;
	std::cout << "Accessing inside x: " << x << std::endl; // First preference local.
	std::cout << "Accessing outside x: " << ::x << std::endl; // for accessing global require scope operator.

	std::cout << "========================= & (REFERENCE VARIABLE) ======================== " << std::endl;
	// Reference variable must be initialized.
	// int &y; y=x;  <------------- it gives error.
	int &y = x; // Reference variable declaration and initialisation.
	std::cout << "Reference var value of y: "<< y << " and value of x:" << x << std::endl;
	
	// Redeclaration or reinitialization not possible
	// int& y = ::x; <-------------- it gives error

	// One reference variable can have multiple reference.
	int &z = x;
	std::cout << "Reference var value of y: " << y << " Reference var value of z: " << z << " and value of x:" << x << std::endl;

	// Constant can't be assign to reference.
	// int &y = 10; <-------------- it gives error.
	// If we modified the reference it affect to original variable also.
	y = 234;
	std::cout << "Reference var value of y: " << y << " Reference var value of z: " << z << " and value of x:" << x << std::endl;
	std::cout << "Address of variable x: " << &x << " Address of referenc variable &y: " << &y << std::endl;

	std::cout << "=========================  NAMESPACE ========================= " << std::endl;
	namespaceFun();

	std::cout << "=========================  MUTABLE ========================= " << std::endl;
	mutableFun();

}

