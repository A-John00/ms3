#include "cnn.h"
#include "matrix.h"
#include <iostream>


using namespace std;

Cnn::Cnn()
{

}

matrix* Cnn::MaxPool3D(matrix* input){
    // 20x20 to 10x10
    matrix* m = new matrix(10, 10, false);
    vector<double> tempvals;
    double temp = 0.00;
    for(int i = 0; i < 20; i = i + 2){
        for(int j = 0; j < 20; j = j + 2){
            tempvals.push_back(input->maxquad(i, j));
        }
    }
    for(int k = 0; k < 10; k++){
        for(int l = 0; l < 10; l++){
            m->setValue(k,l,tempvals.at((k*10 + l)));
        }
    }

    return m;
}



