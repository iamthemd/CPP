#pragma once
#include<iostream>
#include<thread>
#include<mutex>
#include <chrono>
#include <functional>
#include<condition_variable>

class Application1 {
	std::mutex m_Mutex;
	bool m_bSignal;
	std::condition_variable m_cv;
public:
	Application1() {
		m_bSignal = false;
	}

	void LoadData(){
		std::cout << "Load XML Data start\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(10000));
		std::lock_guard<std::mutex> mu(m_Mutex);
		std::cout << "Load XML Data end\n";
		m_bSignal = true;
		m_cv.notify_one();
	}

	bool getSignal() {
		return m_bSignal;
	}

	void MainTask() {
		std::cout << "Hand Shaking start\n";
		std::cout << "Hand Shaking end\n";
		std::unique_lock<std::mutex> uMu(m_Mutex);
		m_cv.wait(uMu, std::bind(&Application1::getSignal, this));
		std::cout << "Data Parsed\n";
	}
};

void Test_ConditionVariable() {
	Application1 app;
	std::thread thread_1(&Application1::MainTask, &app);
	std::thread thread_2(&Application1::LoadData, &app);

	thread_2.join();
	thread_1.join();
}
