#pragma once
#include<iostream>
#include <thread>
#include <future>

class FP {
	int val;
public:
	int getVal() {
		return val;
	}

	void setVal(int argu) {
		val = argu;
	}
};
void initializer(std::promise<FP> *promisePtr) {
	FP fp;
	fp.setVal(123);
	promisePtr->set_value(fp);
}

void Test_FuturePromise() {
	std::promise<FP> promiseObj;
	std::future<FP> futureObj = promiseObj.get_future();
	std::thread th(initializer, &promiseObj);
	std::cout << "Future Object:" << futureObj.get().getVal() << std::endl;
	th.join();
}
