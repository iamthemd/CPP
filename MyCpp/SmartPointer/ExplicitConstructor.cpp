#include <iostream>
#include "ExplicitConstructor.h"

// Explicit is used to mark constructor to not convert implicite type conversion in c++.
Complex::Complex(double r, double i) {
	real = r;
	imag = i;
}

bool Complex::operator==(Complex rhs) {
	return (real == rhs.real && imag == rhs.imag) ? true : false;
}

void Test_ExplicitConstructor() {
	Complex comp(3.00, 0.00);
	if (comp == 3.00) { // Here impicite conversion takes place. To avoid this we have to make constructor explicit.
		std::cout << "Same\n";
	}
	else {
		std::cout << "Not Same\n";
	}
}