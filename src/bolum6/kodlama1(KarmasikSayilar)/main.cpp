#include <iostream>
#include "complexNumber.h"

int main() {
	
	complexNumber complex1;
	complexNumber complex2;
	
	cin>> complex1;
	cin>> complex2;
	
	cout<< complex1;
	cout<< complex2;
	
	complexNumber addComplex = complex1 + complex2;
	complexNumber substractComplex = complex1 - complex2;
	complexNumber multiplyComplex = complex1 * complex2;
	complexNumber multiplyConstant = complex1 * 5;
	
	cout<<addComplex;
	cout<<substractComplex;
	cout<<multiplyComplex;
	cout<<multiplyConstant;
	
	return 0;
}
