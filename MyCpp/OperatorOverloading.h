#pragma once
/* Operator Overloading : Operator overloading means adding extra meaning to the operator without changing 
* Original meaning of operator.
* Syntax : returnType operator symbol (argument)
*        : void operatpr + (argument);
* '::', '.', '.*', '?:' these opetator we can't overload 
*/
class OperatorOverload
{
public: 
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

	/* Why <<, >> operator require friend function to overload.
	* Because 'cout' and 'cin' are object of ostream and istream class and dones't have access of
	* private operation or function of that class.
	*/
	friend std::ostream& operator << (std::ostream&, const OperatorOverload&);
	friend std::istream& operator >> (std::istream&, OperatorOverload&);
};

void Test_OperatorOveload();



