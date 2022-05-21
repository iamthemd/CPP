#pragma once
#include <iostream>
#include <thread>
#include <vector>

class WorkerThread {
public:
	void operator() () {
		std::cout << "Worker Thread:" << std::this_thread::get_id() << "\n";
	}
};

class ThreadRAII {
	std::thread& m_thread;
public:
	ThreadRAII(std::thread& threadObj) : m_thread(threadObj) {
		std::cout << "In ThreadRAII constructor called\n";
	}

	~ThreadRAII() {
		if (m_thread.joinable()) {
			m_thread.join();
		}
	}
};
void Test_threadAttachDetach() {
	std::vector<std::thread> listThread;
	for (int i = 0; i < 10; i++) {
		listThread.push_back(std::thread(WorkerThread()));
	}

	std::cout << "Wait for all worker thread\n";
	for (int i = 0; i < 10; i++) {
		listThread[i].join();
	}

	std::thread detachThread((WorkerThread()));
	detachThread.detach();

	if (detachThread.joinable()) {
		detachThread.join();
	}

	// We should not forget to call join or detach in case of exception.
	// To prevent with we should use Resource Acquisation is initialization(RAII)
	// i.e. check ThreadRAII class
	std::thread thr((WorkerThread()));
	ThreadRAII threadWrap(thr);
}
