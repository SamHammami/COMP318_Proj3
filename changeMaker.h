//
// Created by Ahad Ibrahimi on 4/27/23.
//

#ifndef ASSIGNMENT_4_CHANGEMAKER_H
#define ASSIGNMENT_4_CHANGEMAKER_H

int* greedyChangeMaker(double amount);


class ChangeStruct {
public:
    int totalCoin;
    int solution[5];

};

ChangeStruct dynamicChangeMaker(double amount);

int roundToInt (double);




#endif //ASSIGNMENT_4_CHANGEMAKER_H
