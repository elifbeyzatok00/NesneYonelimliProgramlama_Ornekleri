#include <iostream>
#include "Person.h"
#include <cstdlib>

using namespace std;

int main() {
	
	Person *pArr[] = {new TurkishPerson("Ogun"),
	                  new TurkishPerson("Duygu"),
					  new TurkishPerson("Oguz"),
					  new DeutschePerson("Thomas"),
					  new DeutschePerson("Carl")
	};
					  
					  
	int numberOfPerson = sizeof(pArr) / sizeof(pArr[0]);
	for(int i=0; i<numberOfPerson; i++){
		for(int j=0; j<numberOfPerson; j++){
			if(i != j){
				pArr[i] -> sayHi(*pArr[j]);
			}
		}
		cout <<"\n";
	};
	
	return 0;
}
