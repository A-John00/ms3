#ifndef CNN_H
#define CNN_H
#include "channel.h"
#include "matrix.h"


class Cnn
{
public:
    Cnn(vector<vector<double>> input);


    static matrix* MaxPool3D20to10(matrix* input);
    static matrix* MaxPool3D10to5(matrix* input);

};

#endif // CNN_H
