#pragma once
#include <iostream>
#include <math.h>

using namespace std;

// ax^2 + bx + c = 0
// Where a, b, c are coefficient
// It's root is 
// x = (-b +- sqrt(b^2 - 4ac)) / 2a
// if discriminant x > 0 roots are real and different. 
//    root1 = (-b + sqrt(b^2-4ac)) / 2a
//	  root2 = (-b - sqrt(b^2-4ac)) / 2a
// if discriminant x = 0 roots are real and equal.
//    root1 = root2 = -b / 2a
// if discriminant x > 0 roots are complex and different.
//    root1 = (-b/2a) + i(sqrt(-b^2-4ac)) / 2a
//	  root2 = (-b/2a) - i(sqrt(-b^2-4ac)) / 2a


void RootsOfQuadrantEquation() {
	float a, b, c, discriminant, root1, root2;;
	cout << "Enter the coeeficient a, b, c respective\n";
	cin >> a >> b >> c;
	discriminant = b*b - 4*a*c;
	cout << "Discriminant is " << discriminant << endl;
	if (discriminant > 0) {
		root1 = (-b + sqrt(discriminant)) / (2*a);
		root2 = (-b - sqrt(discriminant)) / (2*a);
		cout << "Roots are real and difference\n";
		cout << "x1 = " << root1 << endl;
		cout << "x2 = " << root2 << endl;
	}
	else if (discriminant == 0) {
		root1 = root2 = -b / (2*a);
		cout << "Roots are real and equal\n";
		cout << "x1 = x2 = "<< root1 <<endl;
	}
	else {
		float realPart = (-b) / (2*a);
		float imaginaryPart = (sqrt(-discriminant)) / (2*a);
		cout << "Roots are Complex and differnt\n";
		cout << "x1 = " << realPart << "+" << imaginaryPart << "i" << endl;
		cout << "x2 = " << realPart << "-" << imaginaryPart << "i" << endl;
	}
}