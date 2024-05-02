
#ifndef COMP318_Proj3_CHANGEMAKER_H
#define COMP318_Proj3_CHANGEMAKER_H

#include <iostream>
#include <cmath>

int* greedyChangeMaker(double amount);


class ChangeStruct {
public:
    int totalCoin;
    int solution[5];

};

ChangeStruct dynamicChangeMaker(double amount);

int roundToInt (double);




#endif //COMP318_Proj3_CHANGEMAKER_H
