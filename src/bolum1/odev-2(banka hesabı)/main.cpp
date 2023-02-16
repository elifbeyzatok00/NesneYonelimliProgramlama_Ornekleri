#include <iostream>
#include "bankAccount.h"
using namespace std;

int main() {
	
	//Bank Account
	bankAccount acc1("Ogun", "Birinci", 5000, "01234567890");
	cout << "Name: " << acc1.getPersonName() << endl;
	cout << "Surname: " << acc1.getPersonSurname() << endl;
	cout << "Phone: " << acc1.getPersonPhone() << endl;
	cout << "Balance: " << acc1.getPersonBalance() << endl;
	
	//copy constractor
	bankAccount acc2(acc1);
	cout << "Name: " << acc2.getPersonName() << endl;
	cout << "Surname: " << acc2.getPersonSurname() << endl;
	cout << "Phone: " << acc2.getPersonPhone() << endl;
	cout << "Balance: " << acc2.getPersonBalance() << endl;
	
	
	acc1.credit(150);
	acc1.displayProfile();
	acc1.withdraw(300);
	acc1.displayProfile();
	
	
	
	bankAccount acc3("Duygu", "Keydal");
	acc3.displayProfile();
	acc1.sendMoney(acc3, 500) ;
	acc3.displayProfile();
	acc1.displayProfile();
	
	return 0;
}
