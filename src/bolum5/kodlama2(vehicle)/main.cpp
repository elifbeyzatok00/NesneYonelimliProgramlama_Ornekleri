#include <iostream>
#include "Vehicle.h"
using namespace std;

int main() {
	
	
	
	//Vehicle
	Vehicle *vPtr[]={new Car(125.850, "BMW"),
	                 new MotorCycle(37.500, "Honda")
	};
	
	int which_vehicle; //Car m� MotorCycle m�
	char inputVehicle; //girilen veriye g�re h�z, vites, motor vs. �al��t�r�lacak
	
	//-1 girilmedi�i s�rece �al��acak 
	do{
		fflush(stdin); //beklemeden ge�mesin. Buffer � temizleyerek bu sorunu ��zer
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
