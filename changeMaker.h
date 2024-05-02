
#ifndef COMP318_Proj3_CHANGEMAKER_H
#define COMP318_Proj3_CHANGEMAKER_H

#include <iostream>
#include <cmath>

using namespace std;

class ChangePlan {
public:
    int totalBills;
    int solution[5];
};
int roundToInt (double);


int* greedyPlan(double amount);
ChangePlan dynamicPlan(double amount);

/**
 * Computes the optimal change plan using dynamic programming.
 *
 * @param amount The total amount of money to compute change for.
 * @return A ChangePlan object containing:
 *   - totalBills: The total number of bills needed for the given amount.
 *   - solution: An array of 5 integers representing the number of each denomination required.
 */



#endif //COMP318_Proj3_CHANGEMAKER_H
