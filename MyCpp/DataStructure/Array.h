#pragma once

/* Array Advantage: 
* - Simple and easy to use
* - Faster access to element ( Constant access)
*  Disadvantage:
* - Size of array is Fixed (static)
* - Insertion/Deletion at given position may need to shift existing element.
*/

template<class T, size_t _size>
class StaticArray {
public:
	// Iterator
	struct Iterator {
				// Iterator constructor
		Iterator(T* p): m_ptr(p){}

		// Implement operator
		T* operator -> () {
			return m_ptr;
		}

		T& operator *() {
			return *m_ptr;
		}

		// Prefix increment
		Iterator& operator ++() {
			m_ptr++;
			return *this;
		}

		// Postfix increment
		Iterator operator ++(int) {
			Iterator temp = *this;
			++(*this);
			return temp;
		}

		friend bool operator == (const Iterator& lhs, const Iterator& rhs) {
			return lhs.m_ptr == rhs.m_ptr;
		}

		friend bool operator != (const Iterator& lhs, const Iterator& rhs) {
			return lhs.m_ptr != rhs.m_ptr;
		}
	private:
		T* m_ptr;
	};

	Iterator begin() {
		return Iterator(&_array[0]);
	};
	Iterator end() {
		return Iterator(&_array[_size]);
	}
	int front();
	int back();
	
	size_t size() const;
	
	int& operator [](int);
	
	int& at(int);
	void swap(StaticArray&);
private:
	T _array[_size];
};

void Test_StaticArray();
