#pragma once
#include <iostream>

//There are three access specifier. public. private, protected.
// public: everything is public, member are accesible from outside class.
// private: member can't access from outside class, inside class member can access.
// protcted: it can access ony throug inherited class, members can't be accessed from outside class.
class AccessSpecifierClass {
public:
	AccessSpecifierClass() {
		x = y = z = 1;
	}
	int x;
private:
	int y;
protected:
	int z;
};

// publc inheritance: public member become public, protected become preotected and private become private
class PublicDeriveClass: public AccessSpecifierClass {
public: 
	void printInPublicDeriveClass() {
		x = 12;
		//y = 23; can't access from outside fuction.
		z = 45;
		std::cout << "X:" << x << "Z:" << z << std::endl;
	}
};

// protected inheritance: public member become protected, protected become protecteds and private become private
class ProtectedDeriveClass : protected AccessSpecifierClass {
public:
	void printInProtectedDeriveClass() {
		x = 14;
		//y = 23; can't access from outside fuction.
		z = 47;
		std::cout << "X:" << x << "Z:" << z << std::endl;
	}
};

// private inheritance: public member become private, protected become private and private become private
class PrivateDeriveClass : private AccessSpecifierClass {
public:
	void printInPrivateDeriveClass() {
		x = 16;
		//y = 23; can't access from outside fuction.
		z = 49;
		std::cout << "X:" << x << "Z:" << z << std::endl;
	}
};


void Test_AccessSpecifier() {
	PublicDeriveClass pubdc; // x is accessible
	pubdc.printInPublicDeriveClass();
	ProtectedDeriveClass prodc; // x is not accessible because it became protected.
	prodc.printInProtectedDeriveClass();
	PrivateDeriveClass pridc; // x is not accessible because it became private
	pridc.printInPrivateDeriveClass();
}
