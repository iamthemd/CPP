#pragma once
#include<iostream>

/* It can be used for any normal conversion between types, 
*  conversions that rely on static (compile-time) type information.
*  This includes any casts between numeric types (for instance : 
*  from short to int or from int to float), casts of pointers and 
*  references up the hierarchy (upcasting).
*/

class baseCast {
public:
	int a;
	virtual void test(){}
};

class deriveCast : public baseCast {
public:
	int b;
};

void Test_StaticCast() {
	int a = 65, b = 2;
	char res1 = a;
	double res = static_cast<double>(a);
	std::cout << "res1:" << res1 << "\n";
	std::cout << "res:" << res << "\n";
	baseCast bObj;
	bObj.a = 9;
	deriveCast dObj;
	dObj.b = 20;
	//dObj.a = 89;
	//----------------------------------
	baseCast& bObj1 = dObj;
	static_cast<deriveCast&>(bObj1);
	//----------------------------------
	//dObj = static_cast<deriveCast>(bObj); Not Possible
	bObj = static_cast<baseCast> (dObj);
	std::cout << bObj.a << "\n";
	//---------------------------------

}
class B{};
class D: public B{};

class BaseD {
	virtual void dummy() {}
};
class DerivedD : public BaseD { };

/* It can only be used with pointers and references to objects.
*  It's almost exclusively used for handling polymorphism.
*  It makes sure that the result of the type conversion is valid 
*  and complete object of the requested class.
*/
void Test_DynamicCast() {
	B b, *bPtr_b;
	D d, *dPtr_d;

	bPtr_b = dynamic_cast<B*>(&d);  // Fine 
	/*
	* Below statement failed because base to derive conversion not allowed
	* unless basae class is polymorphic
	*/
	// dPtr_d = dynamic_cast<D*>(bPtr_b);  // Fail

	BaseD* basePtr_b = new DerivedD{};
	BaseD* basePtr_b1 = new BaseD{};

	DerivedD* derivePtr_d = nullptr;
	DerivedD* derivePtr_d1 = nullptr;


	derivePtr_d = dynamic_cast<DerivedD*>(basePtr_b);  // Fine 
	derivePtr_d1 = dynamic_cast<DerivedD*>(basePtr_b1);  // ptr_d will be NULL 

	// Check if downcasting succeeded 
	if (derivePtr_d != nullptr) {
		std::cout << "derivePtr_d is not null\n";
	}
	else {
		std::cout << "derivePtr_d is null\n";
	}

	if (derivePtr_d1 != nullptr) {
		std::cout << "derivePtr_d1 is not null\n";
	}
	else {
		std::cout << "derivePtr_d1 is null\n";
	}
}

class RBase {
public:
};

class RDerive : public RBase{
public:
};

void Test_ReinterpretCast() {
	RBase* basePtr_b, *basePtr_b1;
	RDerive* derivePtr_d = new RDerive();

	basePtr_b = nullptr;
	RDerive* derivePtr_d1 = nullptr;
	
	basePtr_b = reinterpret_cast<RBase*>(derivePtr_d);
	if (basePtr_b) {
		std::cout << "basePtr_b is not null\n";
	}
	else {
		std::cout << "basePtr_b is null\n";
	}

	derivePtr_d1 = reinterpret_cast<RDerive*>(basePtr_b);
	if (derivePtr_d1) {
		std::cout << "basePtr_b is not null\n";
	}
	else {
		std::cout << "basePtr_b is null\n";
	}
}

void Test_ConstCast() {

}

void Test_PreDefineCast() {
	//Test_StaticCast();
	//Test_DynamicCast();
	Test_ReinterpretCast();
	Test_ConstCast();
}
