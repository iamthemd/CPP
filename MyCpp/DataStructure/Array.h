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
