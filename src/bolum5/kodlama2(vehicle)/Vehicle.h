#include <iostream>
using namespace std;

class Vehicle{
private:
	int speed; //h�z
	int gearNumber; //vites
	bool isWork; //motor �al���yor mu
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
	
	//t�m vehicles(ara�lar) i�in ge�ereli fonksiyonlar� buraya yazal�m
	void startEngine(){
		isWork = true;
		gearNumber = 1;
	}
	void stopEngine(){
		speed = 0;
		isWork = false;
		gearNumber = 0;
	}
	//fonk.lar� en ba�ta virtual tan�mlamak hangi s�n�f �zerinden �a��r�l�yorsa kendi �zelli�ini g�stermesini sa�lar
	virtual void displayInformation(){
		cout<<"Brand: "<< brand <<endl;
		cout<<"Price: "<< price <<endl;
		cout<<"Speed: "<< speed << " and gear: " << gear <<endl;
		isWork ?  cout <<"Engine on"<<endl   :    cout <<"Engine off"<<endl;
		//        motor �al���yorsa buras�        motor �al��m�yorsa buras� �al���r
	}
	virtual void increaseSpeed() = 0; //h�z artt�rma
	virtual void deccreaseSpeed() = 0; //h�z d���rme
	
	//Vehicle s�n�f i�inde virtual fonk.lar yazd�k. bunlar pure virtual fonk. olarak ge�er
	//bir class i�inde 1 tane bile pure virtual fonk. varsa bu s�n�f art�k sanal s�n�f olarak ge�er
	//Vehicle class � art�k virtual(soyut) class olarak ge�er ve bu y�zden bu class tan nesne �retemeyiz
	//��nk� virtual class'tan object �retilemez
	//Ama virtual class'tan miras alan s�n�flar bu durumdan ba��ms�zd�r ve 
	//virtual class'tan miras alan s�n�flardan nesne �retilebilir
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
		//motor zaten �al���yor h�z� ayarlayal�m
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
		//motor zaten �al���yor h�z� ayarlayal�m
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
		//motor zaten �al���yor h�z� ayarlayal�m
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
		//motor zaten �al���yor h�z� ayarlayal�m
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
