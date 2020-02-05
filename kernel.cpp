#include "kernel.h"
#include "matrix.h"
#include <iostream>
#include <random>
#include "time.h"
#include <map>


Kernel::Kernel(int row,int column){
    this->rows = row;
    this->column = column;
    this->kernel = new matrix(row, column, false);
}


void Kernel::Weight(){

    srand (time(NULL));
    for(int i = 0; i < (rows); i++){
        for(int z = 0; z < (column);z++){
            int random_int = (rand( )% 2);  // Decides by random if the weigth number is negativ (0) or positiv (1).
            if (random_int < 1){
                kernel->setValue(i, z, (double)-(rand()% 10000)/10000);  // Inputs random weigths number between 0 and -1 with max 4 digits after the comma.
            }
            else {
                kernel->setValue(i, z, (double)(rand()% 10000)/10000);  // Inputs random weigths number between 0 and 1 with max 4 digits after the comma.
            }
        }
    }
}


void Kernel::LReLU(){
 for(int i = 0; i < (this->rows); i++)
 for(int z = 0; z < (this->column);z++){
    if (kernel->getValue(i,z) < 0){
        kernel->setValue(i, z, kernel->getValue(i,z) * 0.01);
     }
   else{
}
    }
}

void Kernel::Dimension(int r, int c){
    this->rows = r;
    this->column = c;

}

    void Kernel::Print(){
        for(int i = 0; i < (rows); i++){
        for(int z = 0; z < (column);z++){
            cout << kernel->getValue(i, z) << ' ';
    }
        cout << endl;
        }
        cout << endl;
    }


    void Kernel::Reset(){
        matrix* rm = new matrix(0, 0, false);
        kernel = rm;
        this->rows = 0;
        this->column = 0;
    }

    int Kernel::Getter_Rows(){
        return(this->rows);
    }

    int Kernel::Getter_Column(){
        return(this->column);
    }

// anpsassen !!!!!!!!!!!!!!!!!!!!
    /*void Kernel::Get_Kernel(vector<vector<double>> kernel){
        this->kernel.swap(kernel);
    }*/


    void Kernel::Get_rc(int row, int column){
        this->rows = row;
        this->column = column;
    }
