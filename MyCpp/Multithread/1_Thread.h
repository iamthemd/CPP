#pragma once
#include <iostream>
#include <thread>

/* What thread can accept in Constructor ?
* i) Function pointer
* ii) Function object
* iii) Lambda function
*/

class ThreadClass {
public:
	void operator()() {
		std::cout << "Function object called through Operator ():" << 
			this_thread::get_id() << "\n";
	}
};

void thread_fun() {
	std::cout << "Thread function called:" << this_thread::get_id() << "\n";
}

void Test_Thread1() {
	std::thread tObj(thread_fun);
	std::cout << "In main thread\n";
	tObj.join();

	std::thread tFunObj((ThreadClass()));
	tFunObj.join();
	
	std::thread tLambfdaObj([] {
		std::cout << "Lambda Function called:" << this_thread::get_id() << "\n"; });
	tLambfdaObj.join();

	std::cout << "Main thread:" << this_thread::get_id() << "\n";
}
