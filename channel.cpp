#include "channel.h"
#include <string>
#include "kernel.h"
#include "matrix.h"
#include <iostream>
#include <random>
#include "time.h"
#include <map>


//neue get funktion bitte

Channel::Channel(int number_channel,std::string object_name, int rows, int columns){
    this->num_channel = number_channel;
    this->object_name = object_name;
    this->columns = columns;
    this->rows = rows;
}

void Channel::set_numcols(int columns){
    this->columns = columns;
}

void Channel::set_numrows(int rows){
    this->rows = rows;
}


void Channel::LReLU(){
 for(int i = 0; i < (kernels.size()); i++){
    kernels.at(i)->LReLU();
    // goes through the kernels vector and applies the LReLU function to every single one
    }
}



void Channel::Get_rc(int row, int column){
    this->rows = row;
    this->columns = column;
}


// keine ahnung was die macht bitte anpassen/verpassen
// gleiche gilt für die unteren funktionen




void Channel::Clear(){
    vector<Kernel*> nullvector;
    this->kernels = nullvector;
    this->rows = 0;
    this->columns = 0;
    // this->kernels.shrink_to_fit();
}



void Channel::Set(vector<Kernel*> input){
    this->kernels = input;
}


//anpassen

void Channel::Add(matrix* input){
    vector<double> temp;
    for(int i = 0; i < (input.size()); i++){
    for(int z = 0; z < (input[0].size());z++){
        temp.push_back(input[i][z]);
}
this->kernels.push_back(temp);
temp.clear();
  }
    this->rows += input.size();  // Adds the number of added rows to the attribute.
    this->column = input[0].size();
   }







Channel* Channel::Conv3D(int rowb, int columnb){


}







