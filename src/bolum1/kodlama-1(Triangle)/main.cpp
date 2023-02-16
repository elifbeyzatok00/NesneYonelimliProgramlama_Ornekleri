#include <iostream>
#include "Triangle.h"
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {
	
	float a, b, c;
	cout<< "Please enter the sides(a-b-c): " << endl;
	cin>> a>> b >> c; 
	
	Triangle triangle1(a, b, c); //Triangle sýnýfýndan bir triangle1 nesnesi oluþturduk
	//kenar bilgisi girilmeden oluþturulamayacaðý için parametre de verdik
	
	
	Triangle triangle2(triangle1); //triangle2 adýnda copy constructor 
	Triangle triangle3 = triangle1; //triangle3 adýnda copy constructor 
	//Triangle triangle4{a, b, c}; //triangle2 adýnda copy constructor 
	//Triangle triangle5 = {a, b, c}; //triangle3 adýnda copy constructor 
	
	cout << "-Triangle1-" << endl;
	cout << "Side A: " << triangle1.getSideA() << endl;
	cout << "Side B: " << triangle1.getSideB() << endl;
	cout << "Side C: " << triangle1.getSideC() << endl;
	cout << "Area: " << triangle1.calculateArea() << endl;
	
	
	cout << "-Triangle2-" << endl;
	//triangle2.setValue(12,16,20);	
	triangle2.setValue(4,5,3);	
	cout << "Side A: " << triangle2.getSideA() << endl;
	cout << "Side B: " << triangle2.getSideB() << endl;
	cout << "Side C: " << triangle2.getSideC() << endl;
	cout << "Area: " << triangle2.calculateArea() << endl;
	
	triangle1.triangeleType();
	triangle2.triangeleType();
	return 0;
}
