#pragma once
#include <iostream>

/* Function Overloading: function overload means ability to create multiple function of the same name 
*  with different implementation.
*  They are differ on types of argument, number of argument, order of argument. 
*  They are not differ on return type.
*/
class FunctionOverload
{
private:
	int value;
	char ch;
	float f;
	std::string str;
public:
	FunctionOverload();

	void setValue(int, char, float, std::string); // Here Number of argument is four
	void setValue(int, char, std::string, float); // Here Number of argument is four but order is differ than above
	void setValue(int, int, float, std::string); // Here number of argument is four but type of second argument is differ
	void printValue();
};

void Test_FunctionOverload() {

}

