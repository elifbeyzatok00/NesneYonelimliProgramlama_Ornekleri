#include <iostream>
#include <cmath>
#define pi 3.1415
using namespace std;

class Shape{
private:
	double shapeArea; //alan
	double shapeCircumference; //çevre
public:
	double getArea()const{return shapeArea;};
	double getCircumF()const{return shapeCircumference;};
	void setArea(double shape_area){ shapeArea = shape_area;};
	void setCircumF(double c_fr){ shapeCircumference = c_fr;};
	
	virtual void calculateArea() = 0;
	virtual void calculatePerimeter() = 0;
	virtual void display() = 0;
};

class Circle :public Shape{  //Circle-daire
private:
	double radius;
public:
	Circle(double r) {
		radius = r;
	}
	void calculateArea(){
		double area = pi * pow(radius, 2);
		setArea(area);
	}
	void calculatePerimeter(){
		double circum_fr = 2 * pi * radius;
		setCircumF(circum_fr);
	}
	void display(){
		cout <<"------------Circle Information-------------"<<endl;
		cout<<"Radius: "<<radius<<endl;
		cout<<"Area: "<<getArea()<<endl;
		cout<<"Circumference: "<<getCircumF()<<endl;
		
	}
};


class Rectangle :public Shape{  //Rectangle-dikdörtgen
private:
	double width, height;
public:
	Rectangle(double w, double h) {
		width = w;
		height = h;
	}
	void calculateArea(){
		double area = width * height;
		setArea(area);
	}
	void calculatePerimeter(){
		double circum_fr = 2 * (width + height);
		setCircumF(circum_fr);
	}
	void display(){
		cout <<"------------Rectangle Information-------------"<<endl;
		cout<<"Width: "<<width<<endl;
		cout<<"Height: "<<height<<endl;
		cout<<"Area: "<<getArea()<<endl;
		cout<<"Circumference: "<<getCircumF()<<endl;
		
	}
};



