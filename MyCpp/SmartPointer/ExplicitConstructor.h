#pragma once
class Complex
{
	double real;
	double imag;

public:
	//explicit Complex(double r = 0.00, double i = 0.00);
	Complex(double r = 0.00, double i = 0.00);
	bool operator == (Complex rhs);
};

void Test_ExplicitConstructor();

