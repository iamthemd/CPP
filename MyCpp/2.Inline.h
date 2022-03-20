#pragma once
#include <iostream>
/*
* Inline Function: Purpose of the inline function is to optimze the performance interms of function call.
*	- when instruction executing function call usually control pass to the function body.
*     If we define function as inline function, then function call replaced by function body to avoid overhead of
*     transfer control to the function body. But it leads to increase the size of executable size.
*   - It is not necesarry that compiler always replace inline function with funtion body, not like MACRO.
*	- A function defined entirely under class/struct/union definition, whether it's a member function or non-member
*     friend function, is implicitly an inline function.
*	- A function declared as 'constexpr' is implicitly an inline function.
*	- In inline function it is just a request to compiler that if posible replace the fuction call by function definition.
*/

void normal_function() {
	std::cout << "noral_function " << std::endl;
}
class MyClass
{
public:
	void implicitly_Inline_Fun() {
		std::cout << "In implicitly_Inline_Fun() Function\n";
	}

	inline void inline_Fun() {
		std::cout << "In Inline Function\n";
	}
};

