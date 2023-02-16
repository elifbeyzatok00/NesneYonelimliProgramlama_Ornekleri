#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

class Triangle{
	public:
		Triangle(float a, float b, float c);
		~Triangle();
		Triangle(const Triangle& oth);
		bool isTriangle(float a, float b, float c);  //üçgen kontrolü
		float getSideA() const{
			return sideA;
		}
		float getSideB() const{
			return sideB;
		}
		float getSideC() const{
			return sideC;
		}
		void setValue(float a, float b, float c);
		bool isEquilateral(); //eþkenar üçgen mi 
		bool isScalene();     //ikizkenar üçgen mi 
		bool isIsosceles();   //çeþitkenar üçgen mi
		void triangeleType(); //tipleri yazdýrma fonk
		float calculateArea(); //üçgen alan hesaplama
		private:
			float sideA, sideB, sideC;
};

//triangle ýn constructor sýnýfý
Triangle::Triangle(float a, float b, float c){
	while(!isTriangle(a, b, c)){ //a,b,c ile üçgen oluþturulamýyorsa bu döngü çalýþýr
		cout<< "Please enter the sides(a-b-c): " << endl;
		cin>> a>> b >> c; 
	}
	sideA = a;
	sideB = b;
	sideC = c;
	cout << "Triangle created" <<endl;
}

//triangle ýn destructor sýnýfý
Triangle::~Triangle(){
	cout<<"Triangel destroyed" << endl;
}

//triangle ýn copy constructor sýnýfý
Triangle::Triangle(const Triangle &oth){
	sideA = oth.sideA;
	sideB = oth.sideB;
	sideC = oth.sideC;
	cout<<"Triangel copied to target" << endl;
}

void Triangle::setValue(float a, float b, float c){
		while(!isTriangle(a, b, c)){ //a,b,c ile üçgen oluþturulamýyorsa bu döngü çalýþýr
		cout<< "Please enter the sides(a-b-c): " << endl;
		cin>> a>> b >> c; 
	}
	sideA = a;
	sideB = b;
	sideC = c;
	
}

//üçgen oluþturma sýnýfý
bool Triangle::isTriangle(float a, float b, float c){
	//üçgenin oluþabilmesi için þartlar aþaðýdaki gibidir. Bu þartlardan 1 tanesi bile saðlanmazsa üçgen oluþturulamaz 
	//sideA: |b-c|<a<b+c
	//sideB: |a-c|<b<a+c
	//sideC: |a-b|<c<a+b
	
	if(! ( (abs(b-c))<a && (a<b+c) ) ){
		cout << "Invalid A" << endl;  //geçersiz A
		return false;
	}
	if(! ( (abs(a-c))<b && (b<a+c) ) ){
		cout << "Invalid B" << endl;  //geçersiz B
		return false;
	}
	if(! ( (abs(a-b))<c && (c<a+b) ) ){
		cout << "Invalid C" << endl;  //geçersiz C
		return false;
	}
	return true;  //bu üç þarta da girmediyse bu kenar bilgileri ile bir üçgen oluþturulabilir
}

bool Triangle::isEquilateral(){
	return sideA == sideB && sideC == sideB;
}

bool Triangle::isIsosceles(){
	//her eþkenar üçgen ikizkear üçgen belirtir
	if(isEquilateral()){
		return true;
	}else{
		return sideA == sideB || sideB == sideC || sideA == sideC;
	}
}

bool Triangle::isScalene(){
	return !isEquilateral();
	
}

void Triangle::triangeleType(){
	if(isEquilateral()){
		cout<<"Equilateral Triangle" << endl;
	}else if(isIsosceles()){
		cout<<"Isosceles Triangle" << endl;	
	}else{
		cout<<"Scalene Triangle" << endl;	
	}

	
}

float Triangle::calculateArea(){
	float area;
	if(isEquilateral()){
		area=(pow(sideA,2) * sqrt(3) / 4 );
		return area;
	}
	
	float s= (sideA + sideB + sideC) /2;
	area = sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
	return area;
}
