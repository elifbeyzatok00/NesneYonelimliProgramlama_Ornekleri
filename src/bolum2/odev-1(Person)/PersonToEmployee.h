#include <iostream>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Person{
protected:
	string personName, personSurname, personDepartment, personPosition, personID;
	int personSalary, personYear;
public:
	Person(string name, string surname, string department, string position, int salary, int year){
		personName = name;
		personSurname = surname;
		personDepartment = department;
		personPosition = position;
		//personID = ID;
		personSalary = salary;
		personYear = year;
		cout << "Person constructor worked." << endl;
	};
	void setName(string name){ personName = name;};
	void setSurname(string surname){ personSurname = surname;};
	void setDepartment(string department){personDepartment = department;};
	void setPosition(string position){ personPosition = position;};
	void setID(string ID){ personID = ID;};
	void setSalary(int salary){ personYear = salary;};
	void setYear( int  year){  personSalary =  year;};
	
	string getName( ){ return personName;};
	string getSurname( ){ return personSurname;};
	string getDepartment( ){return personDepartment;};
	string getPosition( ){ return personPosition;};
	string getID( ){ return personID;};
	int getSalary( ){ return personSalary;};
	int getYear( ){ return personYear;};
	void print(){
	    cout << "---------------------------" <<endl;
	    cout << "Name: "<< personName << " " << personSurname << endl;
	    cout << "Department: "<< personDepartment << endl;
	    cout << "Position: "<< personPosition <<  endl;
	    cout << "ID Number: "<< personID << endl;
	    cout << "Salary: "<< personSalary << endl;
	    cout << "Years-worked: "<< personYear << endl;
    }
};


class Employee :public Person{
private:
	int employeeBonus;
public:
	Employee(string name, string surname, string department, string position, int salary, int year) :Person(name, surname, department, position, salary, year){
		employeeBonus = 85 * year;
		int randomID = rand() % 8999 + 1000;
		Employee::setID("EMP" + to_string(randomID));
	}
	void print(){
		Person::print();
		cout <<"Bonus: " << employeeBonus <<endl;
		cout <<"-------------------------"<<endl;
		
	}
};

//rand() % 8999 + 1000     -   9000 e kadar ve her oluþturduðum sayýya 1000 ekle

class Manager :public Employee{
	int managerBonus;
public:
	Manager(string name, string surname, string department, string position, int salary, int year) :Employee(name, surname, department, position, salary, year){
		managerBonus = 150 * year;
		int randomID = rand() % 8999 + 1000;
		Manager::setID("MNG" + to_string(randomID)); 
	}
	void print(){
		Person::print();
		cout <<"Bonus: " << managerBonus <<endl;
		cout <<"-------------------------"<<endl;
		
	}
	void extractEmployees(Employee employeesArray[]){
		cout<< "Manager Name: "<<Manager::getName() << " " << Manager::getSurname() << endl;
		cout<< "Manager ID: "<<Manager::getID() <<  endl;
		cout<< "\n" << getDepartment() << "Department Employee List "<<  endl;
		
		
		for(int i = 0;i < sizeof(employeesArray); i++){
			if(getDepartment() == employeesArray[i].getDepartment()){
				employeesArray[i].print();
			}
		}
		
	}
};


/*
getDepartment()           == employeesArray[i].getDepartment()
manager department func.      employees' department func. 

*/

