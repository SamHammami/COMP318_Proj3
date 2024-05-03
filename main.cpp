#include <iostream>
#include "changeMaker.h"

using namespace std;


int main() {
    // User Interaction
    cout << "Welcome to the IR$ of Banana Republic!" << endl;

    string name;
    cout << "Please enter your name: ";
    getline(cin, name);

    double taxAmount;
    cout << "What is your tax $$$ due? ";
    cin >> taxAmount;

    // Compute Change Plans
    int* greedySolution = greedyPlan(taxAmount);
    ChangePlan dynamicSolution = dynamicPlan(taxAmount);

    // Display Results
    cout << endl << "Plan 1: The Greedy Approach" << endl;
    cout << "Tax Due: $" << taxAmount << endl;

    int denominations[] = {95000, 32001, 5001, 701, 101, 1};
    string denomNames[] = {"$95000", "$32001", "$5001", "$701", "$101", "$1"};

    int totalGreedy = 0;
    int subtotalGreedy = 0;

    cout << "Bills\tNum\tSubtotal\n";
    for (int i = 0; i < 6; i++) {
        cout << denomNames[i] << "\tx" << greedySolution[i] << "\t= $" << greedySolution[i] * denominations[i] << endl;
        subtotalGreedy += greedySolution[i] * denominations[i];
        totalGreedy += greedySolution[i];
    }
    cout << "Total number of bills needed: " << totalGreedy << endl;

    cout << "-----------------------------------------------------------------" << endl;

    cout << "\nPlan 2: The Dynamic Programming Approach\n";
    cout << "Tax Due: $" << taxAmount << endl;

    int totalDynamic = 0;
    int subtotalDynamic = 0;

    cout << "Bills\tNum\tSubtotal\n";
    for (int i = 0; i < 6; i++) {
        cout << denomNames[i] << "\tx" << dynamicSolution.solution[i] << "\t= $" << dynamicSolution.solution[i] * denominations[i] << endl;
        subtotalDynamic += dynamicSolution.solution[i] * denominations[i];
        totalDynamic += dynamicSolution.solution[i];
    }
    cout << "Total number of bills needed: " << totalDynamic << endl;

    cout << "-----------------------------------------------------------------" << endl;

    // Select Payment Plan
    int planChoice;
    cout << "Which payment plan do you want to choose (1 or 2)? ";
    cin >> planChoice;

    cout << "\nDear " << name << ", thank you for paying your tax ON TIME!" << endl;

    return 0;
}



//int main() {
//
//    double amount;
//
//    do {
//        cout << "Enter amount in dollars (negative to exit): ";
//        cin >> amount;
//        if (amount < 0) break;
//
//        int *A = greedyPlan(amount);
//
//        cout << "Number of coins in Greedy Algorithm:\n";
//        cout << "  1 cent: " << A[0] << endl;
//        cout << "  7 cents: " << A[1] << endl;
//        cout << "  30 cents: " << A[2] << endl;
//        cout << "  84 cents: " << A[3] << endl;
//        cout << "  235 cents: " << A[4] << endl;
//
//        ChangePlan result = dynamicPlan(amount);
//
//        cout << "Number of coins in Optimal Algorithm:\n";
//        cout << "  1 cent: " << result.solution[0] << endl;
//        cout << "  7 cents: " << result.solution[1] << endl;
//        cout << "  30 cents: " << result.solution[2] << endl;
//        cout << "  84 cents: " << result.solution[3] << endl;
//        cout << "  235 cents: " << result.solution[4] << endl;
//    } while (true);
//
//    return 0;
//}
