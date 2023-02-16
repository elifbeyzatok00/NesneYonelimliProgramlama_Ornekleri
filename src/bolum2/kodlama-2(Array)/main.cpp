#include <iostream>
#include "Array.h"
using namespace std;

int main() {
	
	unsortedArray usArray(10);
	sortedArray sArray(10);
	
	usArray.AddItem(10);
	usArray.AddItem(8);
	usArray.AddItem(12);
	usArray.AddItem(7);
	usArray.AddItem(150);
	usArray.AddItem(5);
	usArray.printItems();
	
	sArray.AddItem(10);
	sArray.AddItem(8);
	sArray.AddItem(12);
	sArray.AddItem(7);
	sArray.AddItem(150);
	sArray.AddItem(5);
	sArray.printItems();
	return 0;
}
