#include <iostream>
using namespace std;

class Vehicle{
private:
	int speed; //hýz
	int gearNumber; //vites
	bool isWork; //motor çalýþýyor mu
	double price; //fiyat
	string brand; //marka
public:
	Vehicle(double vehicle_price = 0.0, string vehicle_brand = " "){
		isWork = false;
		gearNumber = 0;
		speed = 0;
		price = vehicle_price;
		brand = vehicle_brand;
		cout<<"Vehicle constructor worked."<<endl;
	}
	bool getIsWork()const {return isWork;};
	int getSpeed()const {return speed;};
	int getGearNumber()const {return gearNumber;};
	double getPrice()const {return price;};
	string getBrand()const {return brand;};
	
	void setIsWork(bool is_work)const {isWork = is_work;};
	void setSpeed(int speed_)const { speed = speed_;};
	void setGearNumber(int gear_number)const { gearNumber = gear_number;};
	void setPrice(double veh_price)const { price = veh_price;};
	void setBrand(string veh_brand)const { brand = veh_brand;};
	
	//tüm vehicles(araçlar) için geçereli fonksiyonlarý buraya yazalým
	void startEngine(){
		isWork = true;
		gearNumber = 1;
	}
	void stopEngine(){
		speed = 0;
		isWork = false;
		gearNumber = 0;
	}
	//fonk.larý en baþta virtual tanýmlamak hangi sýnýf üzerinden çaðýrýlýyorsa kendi özelliðini göstermesini saðlar
	virtual void displayInformation(){
		cout<<"Brand: "<< brand <<endl;
		cout<<"Price: "<< price <<endl;
		cout<<"Speed: "<< speed << " and gear: " << gear <<endl;
		isWork ?  cout <<"Engine on"<<endl   :    cout <<"Engine off"<<endl;
		//        motor çalýþýyorsa burasý        motor çalýþmýyorsa burasý çalýþýr
	}
	virtual void increaseSpeed() = 0; //hýz arttýrma
	virtual void deccreaseSpeed() = 0; //hýz düþürme
	
	//Vehicle sýnýf içinde virtual fonk.lar yazdýk. bunlar pure virtual fonk. olarak geçer
	//bir class içinde 1 tane bile pure virtual fonk. varsa bu sýnýf artýk sanal sýnýf olarak geçer
	//Vehicle class ý artýk virtual(soyut) class olarak geçer ve bu yüzden bu class tan nesne üretemeyiz
	//çünkü virtual class'tan object üretilemez
	//Ama virtual class'tan miras alan sýnýflar bu durumdan baðýmsýzdýr ve 
	//virtual class'tan miras alan sýnýflardan nesne üretilebilir
};



class Car :public Vehicle{
public:
	Car(double car_price, string car_brand) :public Vehicle(car_price, car_brand){
		price = car_price;
		brand = car_brand;
		cout<<"Car constructor worked."<<endl;
	};
	
	
	void increaseSpeed(){
		if(getIsWork()){  //getIsWork() == true yani engine started
		//motor zaten çalýþýyor hýzý ayarlayalým
	    	int speed_temp = getSpeed();
	    	if(speed_temp <= 120){
	    		int gear_temp = getGearNumber();
	    		setSpeed(speed_temp + 30);
	    		if(gear_temp < 6){
	    			setGearNumber(gear_temp + 1);
				}
			}
		
			
		}else{ //engine stopped So need to start
			cout<<"You should start the engine." << endl;
		}
	}
	
	
	void decreaseSpeed(){
		if(getIsWork()){  //getIsWork() == true yani engine started
		//motor zaten çalýþýyor hýzý ayarlayalým
	    	int speed_temp = getSpeed();
	    	if(speed_temp >= 30){
	    		int gear_temp = getGearNumber();
	    		setSpeed(speed_temp - 30);
	    		if(gear_temp > 2){
	    			setGearNumber(gear_temp - 1);
				}
			}
		
			
		}else{ //engine stopped So need to start
			cout<<"You should start the engine." << endl;
		}
	}
	
	void displayInformation(){
		cout<<"----------------- Car Information -----------------"<<endl;
		Vehicle::displayInformation();
	}
	
};


class MotorCycle :public Vehicle{
public:
	MotorCycle(double motor_price, string motor_brand) :public Vehicle(motor_price, motor_brand){
		price = motor_price;
		brand = motor_brand;
		cout<<"MotorCycle constructor worked."<<endl;
	}
	
	
	void increaseSpeed(){
		if(getIsWork()){  //getIsWork() == true yani engine started
		//motor zaten çalýþýyor hýzý ayarlayalým
	    	int speed_temp = getSpeed();
	    	if(speed_temp <= 90){
	    		int gear_temp = getGearNumber();
	    		setSpeed(speed_temp + 20);
	    		if(gear_temp < 6){
	    			setGearNumber(gear_temp + 1);
				}
			}
		
			
		}else{ //engine stopped So need to start
			cout<<"You should start the engine." << endl;
		}
	}
	
	
	void decreaseSpeed(){
		if(getIsWork()){  //getIsWork() == true yani engine started
		//motor zaten çalýþýyor hýzý ayarlayalým
	    	int speed_temp = getSpeed();
	    	if(speed_temp >= 20){
	    		int gear_temp = getGearNumber();
	    		setSpeed(speed_temp - 20);
	    		if(gear_temp > 2){
	    			setGearNumber(gear_temp - 1);
				}
			}
		
			
		}else{ //engine stopped So need to start
			cout<<"You should start the engine." << endl;
		}
	}
	
	void displayInformation(){
		cout<<"----------------- MotorCycle Information -----------------"<<endl;
		Vehicle::displayInformation();
	}
	
};
