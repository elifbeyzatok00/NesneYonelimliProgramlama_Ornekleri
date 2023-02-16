#include <iostream>
#include <stdio.h>
#include <ctime>
#include "Matrix.h"
using namespace std;

int main(int argc, char** argv) {
	
	//Matrix mainMatrix(-2, -2);
	
	Matrix mainMatrix;
	/*
	for(int i=0; i< 5; i++){
		for(int j=0;j<5;j++){
			mainMatrix.setValue(i, j, i*j);
		}
	}
	*/
	
	
	mainMatrix.randomSet();
	mainMatrix.display();
	
	Matrix mainMatrix2=mainMatrix;
	mainMatrix2.display();
	
	Matrix mainMatrix3.identityMatrixSet();
	mainMatrix3.display();
	
	Matrix result = mainMatrix.addMatrix(mainMatrix2);
	result.display();
	
	return 0;
}
