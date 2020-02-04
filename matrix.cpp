#include "matrix.h"
#include <iostream>
#include <random>
#include "time.h"
#include <map>
#include "channel.h"

using namespace std;

matrix::matrix(int r, int c, bool rdm){
    rows = r;
    columns = c;
    for (int i = 0; i < rows; i++){
        vector<double> colValues;
        for (int j = 0; j < columns; j++){
            double r = 0.00;
            if(rdm){
                r = matrix::genRdm();
            }
            colValues.push_back(r);
        }
        values.push_back(colValues);
    }


}

void matrix::printM(){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            cout << values.at(i).at(j) << "\t\t";
        }
        cout << endl;
    }
}

int matrix::getNumRows(){
    return rows;
}

int matrix::getNumColumns(){
    return columns;
}

void matrix::setValue(int row, int column, double value){
    values.at(row).at(column) = value;
}

double matrix::getValue(int row, int column){
    return values.at(row).at(column);
}

double matrix::genRdm(){
    static random_device rd; // static required for different doubles
    static mt19937 eng(rd());
    uniform_real_distribution<> distr(0, 1);

    return distr(eng);
}

matrix matrix::mult(matrix *a, matrix *b){
    if(a->getNumColumns() != b->getNumRows()){
        cout << "Matrix multiplikation kann nicht durchgeführt werden." << endl;

    }
    matrix* c = new matrix(a->getNumRows(), b->getNumColumns(), false);

    for(int i = 0; i < a->getNumRows(); i++){
        for(int j = 0; j < b->getNumColumns(); j++){
            for(int k = 0; k < b->getNumRows(); k++){
                double tempVal1 = a->getValue(i, k) * b->getValue(k, j);
                double tempVal2 = c->getValue(i, j) + tempVal1;
                c->setValue(i, j, tempVal2);
            }
        }
    }
    return *c;
}




double matrix::maxquad(int rowb, int columnb){
    //row and column bias
    double tempmax = 0.00;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            if(values.at(i+rowb).at(j+columnb) > tempmax){

                tempmax = values.at(i+rowb).at(j+columnb);
            }
        }
    }
    return tempmax;
}
matrix* matrix::helpcon20to20(matrix* a, matrix* b){
    // matrix a is the first matrix
    // so matrices a and b both share the dimension of 20x20
    matrix* za = new matrix(22, 22, false);
    for(int i = 0; i < 22; i++){
        za->setValue(0, i, 0);
        za->setValue(i, 0, 0);
        za->setValue(21, i, 0);
        za->setValue(i, 21, 0);
        // creates the zero border matrix

    }
    for(int j = 0; j < 20; j++){
        for(int k = 0; k < 20; k++){
            za->setValue(j+1, k+1, a->getValue(j, k));
            //sets the zero border matriceses values to the ones of a
        }
    }

}






























