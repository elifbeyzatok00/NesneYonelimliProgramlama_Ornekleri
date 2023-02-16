#include <iostream>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include "PersonToEmployee.h"
using namespace std;

int main() {
	
	Employee employee1 ={"Ogun", "Birinci", "Software", "Engineer", 4500, 5};
	Employee employee2 ={"Eda", "Birinci", "Software", " Engineer", 8500, 5};
	Employee employee3 ={"Burak", "Birinci", "IT","Programmer", 4500, 5};
	Employee employee4 ={"Oguz", "Birinci", "Accounting", " President", 4500, 5};
	
	Manager manager1 ={"Duygu", "Keydal", "Software", " Manager", 8500, 10};
	Manager manager2 ={"Omer", "Selvi", "IT", " Manager", 15000, 25};
	
	Employee employeeList[] = {employee1, employee2, employee3, employee4};
	manager1.extractEmployees(employeeList);
	
	return 0;
}
