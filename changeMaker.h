
#ifndef COMP318_Proj3_CHANGEMAKER_H
#define COMP318_Proj3_CHANGEMAKER_H

#include <iostream>
#include <cmath>

using namespace std;


int* greedyChangeMaker(double amount);


class ChangeStruct {
public:
    int totalBills;
    int solution[5];

};


ChangeStruct dynamicChangeMaker(double amount);

int roundToInt (double);



#endif //COMP318_Proj3_CHANGEMAKER_H
