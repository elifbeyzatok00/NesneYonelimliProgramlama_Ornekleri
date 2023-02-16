#include <iostream>
#include "complexNumber.h"
using namespace std;

int main() {
	
	complexNumber number1(4, 5);
	cout << "Real: " << number1.getReal() <<endl;
	cout << "Imag: " << number1.getImag() <<endl;
	number1.displayComplex();
	
	//negatif de�er al�rsa
	complexNumber number2(4, -6);
	cout << "Real: " << number2.getReal() <<endl;
	cout << "Imag: " << number2.getImag() <<endl;
	number2.displayComplex();
	
	//complexNumber number3(number2);
	complexNumber number3 = number2;   //copy constructor
	number3.displayComplex();
	number3.setValue(4, -7);
	number3.displayComplex();
	
	
	cout << "-----------------------------------------------------" << endl;
	//number1.addComplex(number2);
	complexNumber resultMain;    //bir nesne �retildi
	resultMain = number1.addComplex(number2);   //addComplex ile headerda bir nesne daha �retildi
	resultMain.displayComplex();


	cout << "-----------------------------------------------------" << endl;
	complexNumber resultMain2;    //bir nesne �retildi
	resultMain2 = number1.subtractComplex(number2);   //subtractComplex ile headerda bir nesne daha �retildi
	resultMain2.displayComplex();


	cout << "-----------------------------------------------------" << endl;
	complexNumber resultMain3;    //bir nesne �retildi
	resultMain3 = number1.multiplyConstant(4);   //subtractComplex ile headerda bir nesne daha �retildi
	resultMain3.displayComplex();


	cout << "-----------------------------------------------------" << endl;
	complexNumber resultMain4;    //bir nesne �retildi
	resultMain4 = number1.multiplyComplex(number2);   //subtractComplex ile headerda bir nesne daha �retildi
	resultMain4.displayComplex();


	return 0;
}
