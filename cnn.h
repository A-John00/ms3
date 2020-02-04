#ifndef CNN_H
#define CNN_H
#include "channel.h"
#include "matrix.h"


class Cnn
{
public:
    typedef vector<vector<double>> Mat;
    Cnn();


    static matrix* MaxPool3D(matrix* input);

};

#endif // CNN_H
