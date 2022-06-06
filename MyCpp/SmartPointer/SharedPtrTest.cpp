#include<iostream>
#include "SharedPtrTest.h"

ClassA::ClassA() {
	std::cout << "In ClassA Constructor\n";
	
}

void ClassA::setSharedPtr(std::shared_ptr<ClassB> &bPtr) {
	b_sharedPtr = bPtr;
}

ClassA::~ClassA() {
	std::cout << "In ClassA Destructor\n";
}

ClassB::ClassB() {
	std::cout << "In ClassB Constructor\n";
}

void ClassB::setSharedPtr(std::shared_ptr<ClassA>& aPtr) {
	a_sharedPtr = aPtr;
}

ClassB::~ClassB() {
	std::cout << "In ClassB Destructor\n";
}

void Test_SharedPtrCyclicDependancy() {
	{
		std::shared_ptr<ClassA> ASharedPtr(new ClassA);
		std::shared_ptr<ClassB> BSharedPtr(new ClassB);

		ASharedPtr->setSharedPtr(BSharedPtr);
		BSharedPtr->setSharedPtr(ASharedPtr);

		std::cout << ASharedPtr.use_count() << std::endl;
		std::cout << BSharedPtr.use_count() << std::endl;

		ASharedPtr->~ClassA();
		BSharedPtr->~ClassB();
		std::cout << ASharedPtr.use_count() << std::endl;
		std::cout << BSharedPtr.use_count() << std::endl;

		/*ASharedPtr->~ClassA();
		BSharedPtr->~ClassB();
		std::cout << ASharedPtr.use_count() << std::endl;
		std::cout << BSharedPtr.use_count() << std::endl;*/
	}
}