#include <iostream>

using namespace std;

class complexNumber{
	private:
		int real, imag; //real-gerçel, imaginare-sanal
	public:
		complexNumber(int r=0, int i =0);
		~complexNumber();
		complexNumber(const complexNumber& oth);
		//get fonk const olma nedenei int'ten baðýmsýz çalýþmasý
		int getReal() const{
			return real;
		}
		int getImag() const{
			return imag;
		}
		void setValue(int r = 0, int i = 0);
		complexNumber addComplex(const complexNumber& oth);  //ekleme
		complexNumber subtractComplex( complexNumber& oth); //çýkartma
		complexNumber multiplyComplex(const complexNumber& oth); //çarpma iki kompcleks sayýyý
		complexNumber multiplyConstant(int constant); //çarpma iki sabit  sayýyý
		void multiplyMinus(); //eksi yapma
		void displayComplex();
};

//4+5i   4 gerçek 5 sanal kýsým
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
	//karmaþýk sayýnýn sanal kýsmý: pozitif(>=0) ise ilk kýsým çalýþýr, negatif ise ikinci kýsým çalýþýr
	imag >=0  ?  cout << real <<"+"<< imag << "i" << endl    :    cout << real << imag << "i" << endl;
}


complexNumber complexNumber::addComplex(const complexNumber& oth){
	complexNumber result;   //addComplex ile headerda  nesne  üretilen yer
	result.real = real  + oth.real;  //number1.addComplex(number2);    ise  burada result.real = number1in realý  + number2nin realý
	result.imag = imag  + oth.imag;
	return result ;    //fonksiyonun dönüþ tipi sýnýf ile ayný ise burada copy const çalýþýr
}

//üzerinde deðiþiklik yapacaðýmýz için const tanýmlamadýk
complexNumber complexNumber::subtractComplex( complexNumber& oth){
	complexNumber result;   //subtractComplex ile headerda  nesne  üretilen yer
	oth.multiplyMinus();   //sayýyý eksi yapýyorum
	result = addComplex(oth); //sayýyý eksi olarak toplamaya gönderiyorum  //burada addComplexte 1 nesne daha üretti
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
	return result ;    //fonksiyonun dönüþ tipi sýnýf ile ayný ise burada copy const çalýþýr


}
//3*(4+5i) =  12 + 15i

complexNumber complexNumber::multiplyComplex(const complexNumber& oth){
	complexNumber result;
	result.real = real * oth.real - imag * oth.imag;  
	result.imag = real * oth.imag + imag * oth.real;
	return result ;    //fonksiyonun dönüþ tipi sýnýf ile ayný ise burada copy const çalýþýr


}

