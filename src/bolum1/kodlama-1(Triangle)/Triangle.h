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
		bool isTriangle(float a, float b, float c);  //��gen kontrol�
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
		bool isEquilateral(); //e�kenar ��gen mi 
		bool isScalene();     //ikizkenar ��gen mi 
		bool isIsosceles();   //�e�itkenar ��gen mi
		void triangeleType(); //tipleri yazd�rma fonk
		float calculateArea(); //��gen alan hesaplama
		private:
			float sideA, sideB, sideC;
};

//triangle �n constructor s�n�f�
Triangle::Triangle(float a, float b, float c){
	while(!isTriangle(a, b, c)){ //a,b,c ile ��gen olu�turulam�yorsa bu d�ng� �al���r
		cout<< "Please enter the sides(a-b-c): " << endl;
		cin>> a>> b >> c; 
	}
	sideA = a;
	sideB = b;
	sideC = c;
	cout << "Triangle created" <<endl;
}

//triangle �n destructor s�n�f�
Triangle::~Triangle(){
	cout<<"Triangel destroyed" << endl;
}

//triangle �n copy constructor s�n�f�
Triangle::Triangle(const Triangle &oth){
	sideA = oth.sideA;
	sideB = oth.sideB;
	sideC = oth.sideC;
	cout<<"Triangel copied to target" << endl;
}

void Triangle::setValue(float a, float b, float c){
		while(!isTriangle(a, b, c)){ //a,b,c ile ��gen olu�turulam�yorsa bu d�ng� �al���r
		cout<< "Please enter the sides(a-b-c): " << endl;
		cin>> a>> b >> c; 
	}
	sideA = a;
	sideB = b;
	sideC = c;
	
}

//��gen olu�turma s�n�f�
bool Triangle::isTriangle(float a, float b, float c){
	//��genin olu�abilmesi i�in �artlar a�a��daki gibidir. Bu �artlardan 1 tanesi bile sa�lanmazsa ��gen olu�turulamaz 
	//sideA: |b-c|<a<b+c
	//sideB: |a-c|<b<a+c
	//sideC: |a-b|<c<a+b
	
	if(! ( (abs(b-c))<a && (a<b+c) ) ){
		cout << "Invalid A" << endl;  //ge�ersiz A
		return false;
	}
	if(! ( (abs(a-c))<b && (b<a+c) ) ){
		cout << "Invalid B" << endl;  //ge�ersiz B
		return false;
	}
	if(! ( (abs(a-b))<c && (c<a+b) ) ){
		cout << "Invalid C" << endl;  //ge�ersiz C
		return false;
	}
	return true;  //bu �� �arta da girmediyse bu kenar bilgileri ile bir ��gen olu�turulabilir
}

bool Triangle::isEquilateral(){
	return sideA == sideB && sideC == sideB;
}

bool Triangle::isIsosceles(){
	//her e�kenar ��gen ikizkear ��gen belirtir
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
