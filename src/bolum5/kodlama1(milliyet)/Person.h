#include <iostream>
using namespace std;

class Person{
	string perName;
public:
	Person(string name) { perName = name;};
	string getName()const {return perName;};
	
	//bu fonk. Person sýnýfýndan miras alan sýnýflarýn overwrite ile uluslarýný yazmasý için virtual olarak tanýmlandý
	virtual string getNation()const{  //hangi milliyete aitseniz onu döndürür 
	return " ";
	};
	
	//iki farklý milliyet ise ingilzce merhaba
	//iki ayný milliyet ise kendi dillerinde merhaba
	
	virtual void sayHi(const Person& person){
		cout<<perName<<" says hi "<<person.perName<<endl;
		//perName, person.perName e merhaba dedi
	};
	
	
};

class DeutschePerson :public Person{
public:
	DeutschePerson(string name) :Person(name){};
	string getNation()const{
	return "Deutsche";
	}
	void sayHi(const Person& person){
		if(getNation() == person.getNation()){
			cout<<getName()<<" says Hallo "<<person.getName()<<endl;
		}else{
			Person::sayHi(person);
		}
	}
};

class TurkishPerson :public Person{
public:
	TurkishPerson(string name) :Person(name){};
	string getNation()const{
	return "Turkish";
	}
	void sayHi(const Person& person){
		if(getNation() == person.getNation()){
			cout<<getName()<<" says Merhaba "<<person.getName()<<endl;
		}else{
			Person::sayHi(person);
		}
	}
};
