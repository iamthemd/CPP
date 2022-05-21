#pragma once
#include<iostream>
#include <thread>
#include <vector>
#include <mutex>

/* In multithreading data sharing between threads is very easy, and this cause problem sometime.
* Race Condition: Race condition is problem in mutithread.
*   when two or more thread accessing the same memory location simultaneously. and also 
*   one of thread modifies the data in memory location, then this leads to unexpected
*   behaviour some times, This is called race condition.
*  - Race condition is hard to find and reproduce it, because they don't occure every time.
*   
*/

class Wallet {
	int m_Money;
	std::mutex m_Mutex;  // To fix race condition

public:
	Wallet() {
		m_Money = 0;
	}

	int getMoney() {
		return m_Money;
	}

	void addMoney(int a_Money) {
		std::lock_guard<std::mutex> lockguard(m_Mutex);
		// m_Mutex.lock(); //  lock the resource
		for (int i = 1; i <= a_Money; i++) {
			m_Money++;
		}
		// m_Mutex.unlock(); // unlock the resource
	}
};

int Run() {
	Wallet w;
	std::vector<std::thread> threadVec;
	for (int i = 0; i < 5; i++) {
		threadVec.push_back(std::thread(&Wallet::addMoney, &w, 1000));
	}

	for (int i = 0; i < 5; i++) {
		threadVec[i].join();
	}
	return w.getMoney();
}

void Test_RaceCondition() {
	int val;
	for (int i = 0; i < 1000; i++) {
		if ((val = Run()) != 5000) {
			std::cout << "Error at count " << i << " Money in wallet = " << val << std::endl;
		}
	}
}
