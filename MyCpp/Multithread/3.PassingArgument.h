#pragma once
#include<iostream>
#include<thread>
#include <string>
#include <chrono>

void callBackFunction(std::string *str) {
	std::cout << "Argument Received: " << *str << std::endl;
	std::chrono::milliseconds dura(1000);
	std::this_thread::sleep_for(dura);
	*str = "Changed";
}

void createNewThread() {
	std::string * ptr = new std::string("MD");
	std::thread th(callBackFunction, ptr);
	th.detach();
	std::cout << "Ptr after detach:" << *ptr << std::endl;
	delete ptr;
	ptr = nullptr;
}

void threadCallback(const int &x) {
	std::cout << "In side thread call back function:" << x << std::endl;
	int &a = const_cast<int &>(x);
	a = 90;
}

class Dummy {
public:
	Dummy(){}
	Dummy(const Dummy& obj) {

	}

	void threadFun(std::string str) {
		std::cout << "Inside threeadFun:" << str << std::endl;
	}
};
void Test_ThreadArgument() {
	/*
	createNewThread();
	std::chrono::milliseconds dura(2000);
	std::this_thread::sleep_for(dura);*/
	int x = 10;
	std::thread th(threadCallback, std::ref(x));
	th.join();
	std::cout << "In main function x : " << x << std::endl;
	/*
	Dummy d;
	std::thread threadObj(&Dummy::threadFun, &d, "MDSTR");
	threadObj.join();
	*/
	std::cout << "Finished\n";
}

