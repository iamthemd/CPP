#pragma once
/* Operator Overloading : Operator overloading means adding extra meaning to the operator without changing 
* Original meaning of operator.
* Syntax : returnType operator symbol (argument)
*        : void operatpr + (argument);
* '::', '.', '.*', '?:' these opetator we can't overload 
*/
class OperatorOverload
{
private: 
	int value;
public:
	// Default Constructor
	OperatorOverload():value(0){}
	// Parametrised Constructor
	OperatorOverload(int);

	void Printvalue();

	// Unary Operator
	void operator ++ (); // Prefix increment operator
	void operator -- (); // Prefix decrement operator
	void operator ++ (int); // Postfix increment operator
	void operator -- (int); // Postfix decrement operator

	// Binary operator
	OperatorOverload operator + (const OperatorOverload&);
	OperatorOverload operator - (const OperatorOverload&);
	OperatorOverload operator * (const OperatorOverload&);
	OperatorOverload operator / (const OperatorOverload&);
	bool operator < (const OperatorOverload&);
	bool operator > (const OperatorOverload&);
	bool operator == (const OperatorOverload&);
	bool operator != (const OperatorOverload&);

};

void Test_OperatorOveload();



