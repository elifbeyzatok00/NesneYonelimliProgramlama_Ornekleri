#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;

class Matrix{
private:
	int row, col;
	int ** matrix;
public:
	Matrix(int r = 5, int c = 5);
	~Matrix();
	Matrix(const Matrix& oth);
	int getRowNumber() const{
	return row;
	}
	int getColumnNumber(){
	return col;
	}
	void setValue(int r, int c, int value);
	void randomSet();
	void identityMatrixSet();
	void display();
	Matrix addMatrix(Matrix& othMatrix);
};

Matrix::Matrix(int r, int c){
	
	if(r>0 && c>0){
		row = r;
		col = c;
	}else{
		row = 5;
		col = 5;
	}
	
	matrix = new int* [row];
	for(int i=0; i<row; i++){
		matrix[i] = new int[col];
	}
	cout << "Matrix created" << endl;
	cout << "Row: " << row << endl;
	cout << "Col: " << col << endl;
}

Matrix::~Matrix(){
	for(int i=0; i<row; i++){
		delete[] matrix[i]; // - - - - -'ler silindi 
	}
	delete[] matrix; //matrix[]'ler(iþaretçi dizisi) silindi
	
	cout << "Matrix destroyed" << endl;
}

/*
matrix[0]-> - - - - - 
matrix[1]-> - - - - - 
matrix[2]-> - - - - - 
matrix[3]-> - - - - - 
matrix[4]-> - - - - - 
*/

Matrix::Matrix(const Matrix& oth){
	row = oth.row;
	col = oth.col;
	
	matrix = new int* [row];
	for(int i=0; i<row; i++){
		matrix[i] = new int[col];
	}
	
	//i satýr sayýsý j sütun sayýsý
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			matrix[i][j] = oth.matrix[i][j];
		}
	}
	
	cout << "Matrix copied to target" << endl;
}

/*
- - -   1 2 3
- - -   4 5 6
- - -   7 8 9
*/

//index 0, satýrlar 1 den baþlar
void Matrix::setValue(int r, int c, int value){
	matrix[r][c] = value;  //indexe göre
}

void Matrix::display(){
	cout<<"Matrix: "<<endl;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cout<< matrix[i][j] << " ";
		}
		cout<< "\n ";
	}
	cout<< "\n ";
}

/*
void Matrix::randomSet(){ //bu fonk hangi nesne üzerinden çaðýrýlýyorsa o nesnenin matrisine rastgele deðerler atanacak
	srand(time(NULL));
		for(int i = 0; i < row; i++){
		    for(int j = 0; j < col; j++){
		        matrix[i][j] = rand() % 10;  //% 10  deðer atar. (min 0 max 9)
		    }                                //% 10+1 deðer atar. (min 1 max 10)
		
     	}
}
*/
/*
- - -   
- - -   
- - -
*/

void Matrix::identityMatrixSet(){ //birim matris yapan fonk
	for(int i = 0; i < row; i++){
	    for(int j = 0; j < col; j++){
		    if(i == j){
		    	 matrix[i][j] = 1;
			}else{
				 matrix[i][j] = 0;
			}
		}                               
		
    }
}


Matrix Matrix::addMatrix(const Matrix& othMatrix){
	if(row != othMatrix.row || col != othMatrix.col ){
		cout << "Row and column should be equal" << endl;
		return;
	}else{ //eðer yukarýdaki döngüye girmemiþse satýr ve sütun say. eþittir toplama iþlemine geçebilirim
	Matrix result(row, col);
	for(int i=0;i<result.row;i++){
		for(int j = 0; j <result.col; j++){
			result.matrix[i][j] = matrix[i][j] + othMatrix.matrix[i][j];
		}
	}
	return result;		
	}
	
	
}





