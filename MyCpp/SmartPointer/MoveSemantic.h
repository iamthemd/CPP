#pragma once
#include<iostream>

class Move {
	int* m_ptr;
	int m_size;
public:
	Move(int size)         // Constructor
	{
		m_ptr = new int[size];
		m_size = size;
	}

	~Move()                // Destructor
	{
		delete[] m_ptr;
	}
	Move(const Move& rhs) {
		std::cout << "In Move Construtor\n";
		if (m_ptr != nullptr) {
			delete m_ptr;
		}
		m_ptr = new int[rhs.m_size];
		*m_ptr = *(rhs.m_ptr);
		m_size = rhs.m_size;
	}

	Move(Move&& rhs) noexcept{
		std::cout << "In Move---  && --- Semantic Construtor\n";
		m_ptr = rhs.m_ptr;
		m_size = rhs.m_size;
		rhs.m_ptr = nullptr;
		rhs.m_size = NULL;
	}

	Move& operator = (Move&& rhs) noexcept{
		std::cout << "In Move-- &&--- assignment Operator overload \n";
		if (this == &rhs) {
			return *this;
		}
		if (m_ptr != nullptr) {
			delete[] m_ptr;
		}
		m_ptr = rhs.m_ptr;
		m_size = rhs.m_size;
		rhs.m_ptr = nullptr;
		rhs.m_size = NULL;
		return *this;
	}

	Move& operator =(const Move& rhs) {
		std::cout << "In Move assignment Operator \n";

		if (this == &rhs) {
			return *this;
		}
		if (m_ptr != nullptr) {
			delete[] m_ptr;
		}
		m_ptr = new int[rhs.m_size];
		*m_ptr = *(rhs.m_ptr);
		return *this;
	}

};
Move createMove(int size) {
	return Move(size);
}
void Test_MoveSemantic() {
	
}
