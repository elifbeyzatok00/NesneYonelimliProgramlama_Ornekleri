#include <iostream>
using namespace std;

class Array{
protected:
	int *data, size, capacity;
	public:
	Array(int user_capacity = 5){
		capacity = user_capacity;
     	size = 0;
     	data = new int[capacity];
	    cout<<"Array is created with capacity "<< capacity <<endl;
	};
	~Array(){
	    delete[] data;
     	cout<<"Array destroyed"<<endl;
	};
	Array(const Array& copyArray){
		size = copyArray.size;
	    capacity = copyArray.capacity;
	    data = new int[capacity];
	    for(int i=0;i< copyArray.size;i++){
		    data[i]=copyArray.data[i];
	    }
	    cout<<"Array copied to target"<<endl;
	};
	
void printItems(){
	if(size != 0){
		for(int i=0;i<size;i++){
			cout<<data[i]<<"-"<<endl;
		}
	}
	cout<<"\n"<<"capacity: "<<capacity<< " size: " << size<<endl;
};
	
	
void removeIndexItem(int index){
	if(index < 0 || index >= size) {
		cout << "ERROR! No item at the index" << index <<endl;
		return;
	}
	int removeItem = data[index];
	for(int i = index; i<size; i++) {   
		data[i] = data[i+1];
	}
	size -= 1;
	cout<<"item"<<removeItem<<"is deleted"<<endl;
};	
	
void removeItem(int number){
	int counter = 0;
	for(int i = 0; i <= size; i++){
		if(data[i] == number){
			for(int j = i; j<size; i++){
				data[j] = data[j+1];
			}
			counter += 1;
			i -= 1;
		}
	}
	cout<<counter<<"items (" << number << ")" << " are deleted from the array" << endl;
	size -= counter;
};	
	
int findIndex(int number, int index){
	for(int i=index; i < size; i++ ){
		if(data[i] == number){
			return i;
		}
	}
	return -1;
};

void AddItem(int number){
	if(size== capacity){   //capasite doldu
		int *temp_data=new int[capacity * 2]; //capasiteyi 2 katýna çýkararak arttýralým
		for(int i=0;i<size;i++){
			temp_data[i]=data[i];   //yeni oluþturduðuma bir öncekinden veri aktardým //data yý temp_data ya aktardýk
		}
		delete[] data;   //öncekini datayý sildik
		data= temp_data;  // temp_data, data(pointer) nýn yerini aldý
		capacity *= 2;
	}
	data[size] = number;
	size++;
}
		
};
	
	
class unsortedArray :public Array {
public:
	unsortedArray(int user_capacity = 5) :Array(user_capacity){};
	unsortedArray(const unsortedArray& oth) :Array(oth){};
	void printItems();
};	
	
class sortedArray :public Array {
public:
	sortedArray(int user_capacity = 5) :Array(user_capacity){};
	sortedArray(const sortedArray& oth) :Array(oth){};
	void addItems(int number){
		int i;
	    if(capacity == size){
	    	int*temp_data = new int[capacity *2];
	    	for(int i=0; i<size; i++){
	    		temp_data[i] = data[i];
			}
			delete[] data;
			data = temp_data;
			capacity *= 2;
	    }
	    for(int i=size-1; (i>=0 && data[i]>number); i--)	{
	    	data[i+1] = number;
	    	size++;
		}
			
    }
	void printItems(){
		cout<<"Sorted Array: ";
		Array::printItems();
	}
};
	
	
/*	
	
	int getCapacity() const{
		return capacity;
	}
	void AddItem(int number);
	void printItems();
	void removeIndexItem(int index);
	void removeItem(int number);
	void findElement(int number, int b =0);
};

void Array::findElement(int number, int index){
	int result = findIndex(number, index);
	if(result!=-1){  //eleman bulunduysa
		  cout<<number<<"found at index" << result<<endl;
	}else{
		  cout<<number<<"not found in the array" << endl;
	}
}

*/
