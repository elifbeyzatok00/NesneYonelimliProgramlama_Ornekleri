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
	
	for(unsigned i=0;i<nameOrSurname.length();i++){ //indexlere eriþtik, sýrada indexlerdeki karakterlere eriþmek var 
		if( !( (nameOrSurname.at(i) >= 'A' && nameOrSurname.at(i)<='Z') || (nameOrSurname.at(i)>='a' && nameOrSurname.at(i)<='z') ) ){
		return false;
	    }
	}
	return true;
}

bool bankAccount::controlPhoneNumber(string phoneNumber){
	if(phoneNumber.empty()){ //constructor içinde default olarak boþ atanmýþtý bu yüzden boþ ise true dönmeli
		return true;
	}
	
	if(phoneNumber.length() != 11){ //telefon uzunluðu 11 olmalý
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
	
	while(!controlNameSurname(name)){ //kullanýcý geçerli bir bilgi girmediyse burasý çalýþacak
		cout<< "Invalid Name, please enter your name: ";
		getline(cin, name); //bu deðeri name deðiþkenine alacaðýz
	}
	personName = name;  //kullanýcý geçerli bir isim deðeri girerse döngüye girmeyecek ve bu deðeri personName deðiþkenine atayacaðýz
}

void bankAccount::setPersonSurname(string surname){
	while(!controlNameSurname(surname)){ //kullanýcý geçerli bir bilgi girmediyse burasý çalýþacak
	cout<< "Invalid Surname, please enter your surname: ";
	getline(cin, surname); //bu deðeri surname deðiþkenine alacaðýz
	}
	personSurname = surname;  //kullanýcý geçerli bir isim deðeri girerse döngüye girmeyecek ve bu deðeri personSurname deðiþkenine atayacaðýz

}

void bankAccount::setPersonPhone(string phone){
	while(!controlPhoneNumber(phone)){ //kullanýcý geçerli bir bilgi girmediyse burasý çalýþacak
	cout<< "Invalid Phone, please enter your phone-number: ";
	getline(cin, phone); //bu deðeri surname deðiþkenine alacaðýz
	}
	personPhone = phone;  //kullanýcý geçerli bir isim deðeri girerse döngüye girmeyecek ve bu deðeri personSurname deðiþkenine atayacaðýz

}

void bankAccount::setPersonBalance(float balance){
	if(balance <= 0 ){ //balance negatif ise deðeri 0'layalým
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
	 accountBalance -= amount; //uygun bir amount(miktar) girilirse accountBalance(hesap bakiyesi)aen çýkartýlýr
}

void bankAccount::displayProfile(){
	cout<<"----------------------------- " << endl;
	cout<<"Name: "<<personName<<"\n"<<"Surname: "<<personSurname<<endl;
	if(!personPhone.empty()){ //telefon numarasý giriliyse
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
	 accountBalance -= amount; //uygun bir amount(miktar) girilirse accountBalance(hesap bakiyesi)aen çýkartýlýr
	 othAccount.accountBalance += amount; //aktaracaðým hesaba para eklenir
	 
	 cout << "Balance: "<< accountBalance<<endl;
	 cout << "other account Balance: "<< othAccount.accountBalance<<endl;
}
//othAccount(kopyalanmýþ nesne), deðer ile çaðrý yapýlmýþ. kopyalama yapýldý
// fonk sonunda return etmediði için fonk. sonunda bu kopya yok oldu






