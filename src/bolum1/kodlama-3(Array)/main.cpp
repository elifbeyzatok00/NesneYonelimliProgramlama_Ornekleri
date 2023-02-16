#include <iostream>
#include "Array.h"
using namespace std;

int main() {
	Array mainArray(10);
	Array mainArray2(mainArray);
	cout<<"Capacity: "<< mainArray.getCapacity()<<endl;
	cout<<"Size: "<< mainArray.getSize()<<endl;
	
	cout<<"Capacity: "<< mainArray2.getCapacity()<<endl;
	cout<<"Size: "<< mainArray2.getSize()<<endl;
	
	
	mainArray.AddItem(5);
	mainArray.AddItem(12);
	mainArray.AddItem(3);
	mainArray.AddItem(8);
	mainArray.AddItem(7);
	mainArray.AddItem(2);
	mainArray.AddItem(4);
	mainArray.AddItem(6);
	mainArray.AddItem(9);
	mainArray.AddItem(10);
	mainArray.printItems();
	mainArray.AddItem(41);
	mainArray.printItems();
	
	Array mainArray3 = mainArray;
	mainArray3.printItems();
	mainArray3.AddItem(15);
	mainArray3.AddItem(18);
	

	mainArray.printItems();
	mainArray3.printItems();
	
	
	mainArray3.removeIndexItem(-1);
	mainArray3.printItems();
	
	mainArray3.removeItem(3);
	mainArray3.printItems();
	
	mainArray3.findElement(12, 2);
	
	return 0;
}

