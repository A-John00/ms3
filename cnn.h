#ifndef CNN_H
#define CNN_H
#include "channel.h"
#include "matrix.h"


class Cnn
{
public:
    Cnn(matrix* input);

    static matrix* Conv3D28to32(matrix* input);

    static matrix* MaxPool3D20to10(matrix* input);
    static matrix* MaxPool3D10to5(matrix* input);

};

#endif // CNN_H
