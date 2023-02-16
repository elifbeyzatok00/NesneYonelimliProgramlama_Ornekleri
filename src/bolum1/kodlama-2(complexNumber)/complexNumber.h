#include <iostream>

using namespace std;

class complexNumber{
	private:
		int real, imag; //real-ger�el, imaginare-sanal
	public:
		complexNumber(int r=0, int i =0);
		~complexNumber();
		complexNumber(const complexNumber& oth);
		//get fonk const olma nedenei int'ten ba��ms�z �al��mas�
		int getReal() const{
			return real;
		}
		int getImag() const{
			return imag;
		}
		void setValue(int r = 0, int i = 0);
		complexNumber addComplex(const complexNumber& oth);  //ekleme
		complexNumber subtractComplex( complexNumber& oth); //��kartma
		complexNumber multiplyComplex(const complexNumber& oth); //�arpma iki kompcleks say�y�
		complexNumber multiplyConstant(int constant); //�arpma iki sabit  say�y�
		void multiplyMinus(); //eksi yapma
		void displayComplex();
};

//4+5i   4 ger�ek 5 sanal k�s�m
complexNumber::complexNumber(int r, int i){
	real = r;
	imag = i;
	cout << "Complex Number created." << endl;
}

complexNumber::~complexNumber(){
		cout << "Complex Number destroyed." << endl;
}

complexNumber::complexNumber(const complexNumber &oth){
	real = oth.real;
	imag = oth.imag;
	cout << "Complex Number copied to target." << endl;
}

void complexNumber::setValue(int r, int i){
	real = r;
	imag = i;
}

void complexNumber::displayComplex(){	
	//karma��k say�n�n sanal k�sm�: pozitif(>=0) ise ilk k�s�m �al���r, negatif ise ikinci k�s�m �al���r
	imag >=0  ?  cout << real <<"+"<< imag << "i" << endl    :    cout << real << imag << "i" << endl;
}


complexNumber complexNumber::addComplex(const complexNumber& oth){
	complexNumber result;   //addComplex ile headerda  nesne  �retilen yer
	result.real = real  + oth.real;  //number1.addComplex(number2);    ise  burada result.real = number1in real�  + number2nin real�
	result.imag = imag  + oth.imag;
	return result ;    //fonksiyonun d�n�� tipi s�n�f ile ayn� ise burada copy const �al���r
}

//�zerinde de�i�iklik yapaca��m�z i�in const tan�mlamad�k
complexNumber complexNumber::subtractComplex( complexNumber& oth){
	complexNumber result;   //subtractComplex ile headerda  nesne  �retilen yer
	oth.multiplyMinus();   //say�y� eksi yap�yorum
	result = addComplex(oth); //say�y� eksi olarak toplamaya g�nderiyorum  //burada addComplexte 1 nesne daha �retti
	return result ;

}
//4+5i - (5+7i) = 4+5i -5-7i

void complexNumber::multiplyMinus(){
	real *= -1;
	imag *= -1;
}

complexNumber complexNumber::multiplyConstant(int constant ){
	complexNumber result;
	result.real = real  * constant;  
	result.imag = imag  * constant;
	return result ;    //fonksiyonun d�n�� tipi s�n�f ile ayn� ise burada copy const �al���r


}
//3*(4+5i) =  12 + 15i

complexNumber complexNumber::multiplyComplex(const complexNumber& oth){
	complexNumber result;
	result.real = real * oth.real - imag * oth.imag;  
	result.imag = real * oth.imag + imag * oth.real;
	return result ;    //fonksiyonun d�n�� tipi s�n�f ile ayn� ise burada copy const �al���r


}

