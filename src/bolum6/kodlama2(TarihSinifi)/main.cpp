#include <iostream>
#include "Date.h"

int main() {
	
	
	Date firstDate(19, 07, 1999);
	Date secondtDate(26, 07, 1999);
	
	cout << firstDate;
	cout << secondtDate;
	
	cout << "-----------------------"<<endl;
	for(int i=0;i<30;i++){
		firstDate++;
		cout<<firstDate;
	}
	
	
	if(firstDate > secondtDate){
		cout << "First date is greater" << endl;
	}else {
		return "false";
	}
	
	return 0;
}
