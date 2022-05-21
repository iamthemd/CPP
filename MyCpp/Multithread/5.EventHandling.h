#pragma once
#include<iostream>
#include <thread>
#include <mutex>

class Application {
	bool m_bSignal;
	std::mutex m_Mutex;
public:
	Application() {
		m_bSignal = false;
	}
	void LoadData() {	
		std::cout << "Loading XML Data start\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(10000));
		std::lock_guard<std::mutex> mu(m_Mutex);
		std::cout << "Loading XML finished";
		m_bSignal = true;
	}

	void MainTask() {
		std::cout << "HandShaking start\n";
		std::cout << "HandShaking Done\n";
		m_Mutex.lock();
		while (m_bSignal != true)
		{
			m_Mutex.unlock();
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			std::cout << "Waiting to finished Load xml\n";
			m_Mutex.lock();
		}
		m_Mutex.unlock();
		std::cout << "Processing XML Data\n";
		std::cout << "Processed XML Data\n";
	}
};

void Test_EventHandling() {
	Application app;
	std::thread thread_1(&Application::MainTask, &app);
	std::thread thread_2(&Application::LoadData, &app);

	thread_2.join();
	thread_1.join();
}
