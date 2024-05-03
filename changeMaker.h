
#ifndef COMP318_Proj3_CHANGEMAKER_H
#define COMP318_Proj3_CHANGEMAKER_H

#include <iostream>
#include <array> // For Greedy Programming
#include <vector> // For Dynamic Programming
#include <cmath> // For INT_MAX
#include <string> // For string manipulation
#include <iomanip> // For setw


using namespace std;

class ChangePlan {
    // Class to store the plan of bills and the total number of bills
public:
    array<int, 6> plan; // The plan of bills
    int totalBills; // Total number of bills
};

array<int, 6> greedyPlan(int taxAmount);
ChangePlan dynamicPlan(int taxAmount);


#endif //COMP318_Proj3_CHANGEMAKER_H
