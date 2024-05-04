
#include "changeMaker.h"


array<int, 6> greedyPlan(int taxAmount, const array<int, 6> &denominations){
//    // Array of denominations
//    const int denominations[6] = {95000, 32001, 5001, 701, 101, 1} ;
    // Array to store the plan
    array<int, 6> plan = {0}; // Initialize all elements to 0

    for (int i = 0; i < 6; ++i) {
        plan[i] = taxAmount / denominations[i];
        taxAmount %= denominations[i];
    }

    return plan;
}

ChangePlan dynamicPlan(int taxAmount, array<int, 6> denominations) {
//     Array of denominations
//    const int denominations[6] = {95000, 32001, 5001, 701, 101, 1};
    // Vector of ChangePlan objects
    vector<ChangePlan> dynaProg(taxAmount + 1);

    // Base case
    dynaProg[0].totalBills = 0;
    dynaProg[0].plan.fill(0);

    for (int i = 1; i <= taxAmount; ++i) {
        dynaProg[i].totalBills = INT_MAX;

        for (int j = 0; j < 6; ++j) {
            if (i >= denominations[j]) {
                ChangePlan newSolution = dynaProg[i - denominations[j]];
                newSolution.totalBills++;
                newSolution.plan[j]++;

                if (newSolution.totalBills < dynaProg[i].totalBills) {
                    dynaProg[i] = newSolution;
                }
            }
        }
    }

    return dynaProg[taxAmount]; // Return the plan for the given tax amount
}