
#ifndef COMP318_Proj3_CHANGEMAKER_H
#define COMP318_Proj3_CHANGEMAKER_H

#include <iostream>
#include <array> // For Greedy Programming
#include <vector> // For Dynamic Programming
#include <cmath> // For INT_MAX
#include <iomanip> // For setw

using namespace std;

// Class to store the plan of bills and the total number of bills
class ChangePlan {
    // No need for private members since we are using a struct
    // But better to use private members then call them
    // Using getters and setters instead of public members
public:
    array<int, 6> plan; // The plan of bills
    int totalBills; // Total number of bills
};

// Function Prototypes Logic (Greedy & Dynamic)
array<int, 6> greedyPlan(int taxAmount, const array<int, 6> &denominations);
ChangePlan dynamicPlan(int taxAmount, const array<int, 6> &denominations);

// Display Prototypes
void displayGreedyApproach(int taxAmount, const array <int, 6> &denominations);
void displayDynamicApproach(int taxAmount, const array <int, 6> &denominations);


#endif //COMP318_Proj3_CHANGEMAKER_H
