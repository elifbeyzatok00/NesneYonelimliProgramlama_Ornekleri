#include <iostream>
#include "Person.h"
#include <time.h>
#include <conio.h>
#include <stdlib.h>
//using namespace std;

int main(){
	
	
	srand(time(NULL));
	Student studentArray[] = { {"Ogun", "Birinci", 1000}, 
	                           {"Duygu", "Keydal", 1001},
							   {"Eda", "Deniz", 1002},
							   {"Burak", "Ikinci", 1003}
	};
	Teacher teacher1("Oguz", "Birinci", "Software");
	
	for(int i=0;i<4;i++){
		studentArray[i].setStudentGrade( rand() % 100 + 1 ); //1-100 arasý random bir puan alacak
		studentArray[i].print();
	}
	
	teacher1.passFailStatus(studentArray);
	teacher1.printStudentInformation(studentArray);

	
	return 0;
}

/*
% 100 + 1      1-100
% 100          0-99
*/


