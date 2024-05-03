
#include "changeMaker.h"


array<int, 6> greedyPlan(int taxAmount, int[] denominations) {
    array<int, 6> plan = {0}; // Initialize all elements to 0

    for (int i = 0; i < denominations.size(); ++i) {
        plan[i] = taxAmount / denominations[i];
        taxAmount %= denominations[i];
    }

    return plan;
}

ChangePlan dynamicPlan(int taxAmount, int[] denominations) {
    // Vector of ChangePlan objects
    vector<ChangePlan> dynaProg(taxAmount + 1);

    // Base case
    dynaProg[0].totalBills = 0;
    dynaProg[0].plan.fill(0);

    for (int i = 1; i <= taxAmount; ++i) {
        dynaProg[i].totalBills = INT_MAX;

        for (int j = 0; j < denominations.size(); ++j) {
            if (i >= denominations[j]) {
                ChangePlan candidate = dynaProg[i - denominations[j]];
                candidate.totalBills++;
                candidate.plan[j]++;

                if (candidate.totalBills < dynaProg[i].totalBills) {
                    dynaProg[i] = candidate;
                }
            }
        }
    }

    return dynaProg[taxAmount]; // Return the plan for the given tax amount
}