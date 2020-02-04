#include "cnn.h"
#include "matrix.h"
#include <iostream>
#include "channel.h"


using namespace std;

Cnn::Cnn(vector<vector<double>> input)
{
    Channel* ch0 = new Channel(0, "first", 0, 0);
    ch0->Add(input);
    ch0->set_numcols(1);
    ch0->set_numrows(input.size());
    // adds input into the first channel/layer of the cnn
}

matrix* Cnn::MaxPool3D20to10(matrix* input){
    // 20x20 to 10x10
    matrix* m = new matrix(10, 10, false);
    vector<double> tempvals;
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
    //returns ONE resulting matrix of Maxpool3D 20x20 to 10x10
}

matrix* Cnn::MaxPool3D10to5(matrix* input){
    // 10x10 to 5x5
    matrix* m = new matrix(5, 5, false);
    vector<double> tempvals;
    for(int i = 0; i < 10; i = i + 2){
        for(int j = 0; j < 10; j = j + 2){
            tempvals.push_back(input->maxquad(i, j));
        }
    }
    for(int k = 0; k < 5; k++){
        for(int l = 0; l < 5; l++){
            m->setValue(k,l,tempvals.at((k*5 + l)));
        }
    }

    return m;
    //returns ONE resulting matrix of Maxpool3D 10x10 to 5x5
}



