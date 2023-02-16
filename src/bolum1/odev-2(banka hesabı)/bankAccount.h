#include <iostream>
using namespace std;

class bankAccount{
public:
	bankAccount(string name, string surname, float balance=0, string phone_number = "");
	bankAccount(const bankAccount& othAccount);
	~bankAccount();
	bool controlNameSurname(string nameOrSurname);
	bool controlPhoneNumber(string phoneNumber);
	void displayProfile();
	void credit(float);
	void withdraw(float);
	void sendMoney(bankAccount& othAccount, float amount);
	void setPersonName(string name);
	void setPersonSurname(string surname);
	void setPersonPhone(string phone);
	void setPersonBalance(float balance=0);  //balance = bakiye 
	string getPersonName() const{
		return personName;
	}
	string getPersonSurname() const{
		return personSurname;
	}
	string getPersonPhone() const{
		return personPhone;
	}
	int getPersonBalance() const{
		return accountBalance;
	}
private:
	float accountBalance;
	string personName, personSurname, personPhone;
};

bool bankAccount::controlNameSurname(string nameOrSurname){
	
	for(unsigned i=0;i<nameOrSurname.length();i++){ //indexlere eri�tik, s�rada indexlerdeki karakterlere eri�mek var 
		if( !( (nameOrSurname.at(i) >= 'A' && nameOrSurname.at(i)<='Z') || (nameOrSurname.at(i)>='a' && nameOrSurname.at(i)<='z') ) ){
		return false;
	    }
	}
	return true;
}

bool bankAccount::controlPhoneNumber(string phoneNumber){
	if(phoneNumber.empty()){ //constructor i�inde default olarak bo� atanm��t� bu y�zden bo� ise true d�nmeli
		return true;
	}
	
	if(phoneNumber.length() != 11){ //telefon uzunlu�u 11 olmal�
		return false;
	}
	
	for(unsigned i=0;i<phoneNumber.length();i++){
		if(!(phoneNumber.at(i)>='0' && phoneNumber.at(i)<='9')){
		return false;
	    }
	}
	return true;
}

bankAccount::bankAccount(string name, string surname, float balance , string phone_number){
	setPersonName(name);
	setPersonSurname(surname);
	setPersonPhone(phone_number);
	setPersonBalance(balance);
	cout<<"Bank Account created" << endl;
}

bankAccount::~bankAccount(){
	cout << "Bank Account destroyed" << endl;
}

bankAccount::bankAccount(const bankAccount& othAccount){
	personName = othAccount.personName;
	personSurname = othAccount.personSurname;
	personPhone = othAccount.personPhone;
	accountBalance = othAccount.accountBalance;
	cout << "Bank Account copied to target" << endl;
}

void bankAccount::setPersonName(string name){
	
	while(!controlNameSurname(name)){ //kullan�c� ge�erli bir bilgi girmediyse buras� �al��acak
		cout<< "Invalid Name, please enter your name: ";
		getline(cin, name); //bu de�eri name de�i�kenine alaca��z
	}
	personName = name;  //kullan�c� ge�erli bir isim de�eri girerse d�ng�ye girmeyecek ve bu de�eri personName de�i�kenine atayaca��z
}

void bankAccount::setPersonSurname(string surname){
	while(!controlNameSurname(surname)){ //kullan�c� ge�erli bir bilgi girmediyse buras� �al��acak
	cout<< "Invalid Surname, please enter your surname: ";
	getline(cin, surname); //bu de�eri surname de�i�kenine alaca��z
	}
	personSurname = surname;  //kullan�c� ge�erli bir isim de�eri girerse d�ng�ye girmeyecek ve bu de�eri personSurname de�i�kenine atayaca��z

}

void bankAccount::setPersonPhone(string phone){
	while(!controlPhoneNumber(phone)){ //kullan�c� ge�erli bir bilgi girmediyse buras� �al��acak
	cout<< "Invalid Phone, please enter your phone-number: ";
	getline(cin, phone); //bu de�eri surname de�i�kenine alaca��z
	}
	personPhone = phone;  //kullan�c� ge�erli bir isim de�eri girerse d�ng�ye girmeyecek ve bu de�eri personSurname de�i�kenine atayaca��z

}

void bankAccount::setPersonBalance(float balance){
	if(balance <= 0 ){ //balance negatif ise de�eri 0'layal�m
		accountBalance = 0;
	}else{
		accountBalance = balance;
	}
}




void bankAccount::credit(float amount){
	
	while(amount <= 0){
		cout<<"Invalid amount; please enter valid amount: ";
		cin>> amount;
	}
	
	accountBalance += amount; //uygun bir amount(miktar) girilirse accountBalance(hesap bakiyesi)ne eklenir
}

void bankAccount::withdraw(float amount){
	 
	 while(amount <= 0 || amount > accountBalance){
	 	cout << "Invalid amount; please enter valid amount: ";
	 	cin>>amount;
	 }
	 accountBalance -= amount; //uygun bir amount(miktar) girilirse accountBalance(hesap bakiyesi)aen ��kart�l�r
}

void bankAccount::displayProfile(){
	cout<<"----------------------------- " << endl;
	cout<<"Name: "<<personName<<"\n"<<"Surname: "<<personSurname<<endl;
	if(!personPhone.empty()){ //telefon numaras� giriliyse
		cout<<"Phone Number: " << personPhone<<endl;
	}else{
		cout << "Phone Number: None ";
	}
	cout << "Balance: "<< accountBalance<<endl;
}

void bankAccount::sendMoney(bankAccount &othAccount, float amount){ 
	while(amount <= 0 || amount > accountBalance){
	 	cout << "Invalid amount; please enter valid amount: ";
	 	cin>>amount;
	 }
	 accountBalance -= amount; //uygun bir amount(miktar) girilirse accountBalance(hesap bakiyesi)aen ��kart�l�r
	 othAccount.accountBalance += amount; //aktaraca��m hesaba para eklenir
	 
	 cout << "Balance: "<< accountBalance<<endl;
	 cout << "other account Balance: "<< othAccount.accountBalance<<endl;
}
//othAccount(kopyalanm�� nesne), de�er ile �a�r� yap�lm��. kopyalama yap�ld�
// fonk sonunda return etmedi�i i�in fonk. sonunda bu kopya yok oldu






