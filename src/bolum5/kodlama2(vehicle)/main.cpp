#include <iostream>
#include "Vehicle.h"
using namespace std;

int main() {
	
	
	
	//Vehicle
	Vehicle *vPtr[]={new Car(125.850, "BMW"),
	                 new MotorCycle(37.500, "Honda")
	};
	
	int which_vehicle; //Car mý MotorCycle mý
	char inputVehicle; //girilen veriye göre hýz, vites, motor vs. çalýþtýrýlacak
	
	//-1 girilmediði sürece çalýþacak 
	do{
		fflush(stdin); //beklemeden geçmesin. Buffer ý temizleyerek bu sorunu çözer
		cout<< "Enter vehicle and input: ";
		cin>>which_vehicle>>" ">>inputVehicle>>endl;
		
		switch(inputVehicle){
			case 'U': //Upper
				vPtr[which_vehicle] -> increaseSpeed();
				vPtr[which_vehicle] -> displayInformation();
				break;
			case 'D':  //Down
				vPtr[which_vehicle] -> decreaseSpeed();
				vPtr[which_vehicle] -> displayInformation();
				break;
			case 'C': //Close
				vPtr[which_vehicle] -> stopEngine();
				vPtr[which_vehicle] -> displayInformation();
				break;
			case 'S': //Start
				vPtr[which_vehicle] -> startEngine();
				vPtr[which_vehicle] -> displayInformation();
				break;
			default: 
				cout<<"Enter valid input: ";
				break;
			
		}
		
		
	}while( which_vehicle != -1);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
