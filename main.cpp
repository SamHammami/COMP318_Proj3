/* --------------------------------- Wheaton College MA - Spring 2024 ---------------------------------*\
 * Comp 318, programming project 3
 * Sam Hammami '25
 */

#include "changeMaker.h"
#include <iostream>

using namespace std;


/*--------------------------------Display (Greedy) & (Dynamic) Approach------------------------------------*/

                                /*------- Greedy Approach -------*/
void displayGreedyApproach(int taxAmount, const array <int, 6> &denominations) {

    // Get the greedy plan
    array<int, 6> greedyResult = greedyPlan(taxAmount, denominations);

    // Start displaying the greedy result
    cout << "Plan 1: The Greedy Approach" << endl;
    cout << "Tax Due: $" << taxAmount << endl;
    cout << setw(16) << " " ; //Spacing to push table
    cout << left << setw(14) << "Bills" << setw(22) << "Num" << "Subtotal" << endl;

    int subtotalGreedy = 0;
    string storeGreedyBills; // rename to => no storeGreedyBills to
    int totalBillsGreedy = 0;
    // Loop through the greedy result
    for (size_t i = 0; i < greedyResult.size(); ++i) { //greedyResult.size()= 6 -> from greedyPlan function

        // Display: Bills x Number of Bills = Total (Greedy)
        int bills = denominations[i];
        int num = greedyResult[i];
        cout << setw(16) << " " << "$" << setw(8) << bills << setw(5) << "x" << setw(6) << num;
        cout << "= $" << setw(12) << num * bills;

        // Display the subtotal (Greedy)
        subtotalGreedy += num * bills;
        if (i > 0) {
            storeGreedyBills += " + ";
        }
        storeGreedyBills += to_string(num);
        cout << " $" << subtotalGreedy << endl;

        // Helper variable to calculate the total number of bills
        totalBillsGreedy += num;
    }
    // Display the total number of bills one by one (Greedy)
    cout << endl << "Total number of bills needed: " << storeGreedyBills << " = " << totalBillsGreedy << endl;
}

                                /*------- Dynamic Approach -------*/
void displayDynamicApproach(int taxAmount, const array <int, 6> &denominations) {

    // Get the dynamic plan
    ChangePlan dynamicResult = dynamicPlan(taxAmount, denominations);

    // Start displaying the dynamic result
    cout << "Plan 2: The Dynamic Programming Approach" << endl;
    cout << "Tax Due: $" << taxAmount << endl;
    cout << setw(16) << " "; //Spacing to push table
    cout << left << setw(14) << "Bills" << setw(22) << "Num" << "Subtotal" << endl;

    int subtotalDynamic = 0;
    string storeDynamBills;
    // Loop through the dynamic result
    for (size_t i = 0; i < dynamicResult.plan.size(); ++i) { //dynamicResult.plan.size()= 6 -> from dynamicPlan function
        // Display: Bills x Number of Bills = Total (Dynamic)
        int bills = denominations[i];
        int num = dynamicResult.plan[i];
        cout << setw(16) << " " << "$" << setw(8) << bills << setw(5) << "x" << setw(6) << num;
        cout << "= $" << setw(12) << num * bills;

        // Display the subtotal (Dynamic)
        subtotalDynamic += num * bills;
        if (i > 0) {
            storeDynamBills += " + ";
        }
        storeDynamBills += to_string(num);
        cout << " $" << subtotalDynamic << endl;

    }
    // Display the total number of bills one by one (Dynamic)
    cout << endl << "Total number of bills needed: " << storeDynamBills << " = " << dynamicResult.totalBills << endl;

}

/*-------------------------------------------------Main Function-------------------------------------------------*/
int main() {


    cout << "Welcome to the IR$ of Banana Republic!" << endl << endl;

    string name = "Poor Patrick"; //Houssam
//    string name;
//    cout << "Please enter your name below! " << endl;
//    cout << "My Name is";
//    getline(cin, name);

//    int taxAmount = 96003; // Test case: no= 303, no=1003, no=5003, 7003, 32003, 95003, 96003 (for dynamic), 3333333
    int taxAmount;
    cout << endl << "What is your tax $$$ due? " << endl;
    cout << "My Tax Amount Due = $";
    cin >> taxAmount;

    // Array of bill denominations
    const array<int, 6> denominations = {95000, 32001, 5001, 701, 101, 1};

    // Display the greedy and dynamic approaches
    cout << endl << "---------------------------------------------------------------" << endl;
    displayGreedyApproach(taxAmount, denominations);
    cout << "*-----------------------------*****---------------------------*" << endl;
    displayDynamicApproach(taxAmount, denominations);
    cout << "---------------------------------------------------------------" << endl;

    // Select Payment Plan
    int planChoice = 0;

    while (planChoice != 1 && planChoice != 2) {
        cout << "Which payment plan do you want to choose (1 or 2)? " << endl;
        cout << "Plan: ";
        cin >> planChoice;

        if (!(!cin.fail() && !(planChoice != 1 && planChoice != 2))) {
            cout << "Invalid choice. Please enter 1 or 2." << endl;
            planChoice = 0; // Reset choice to force re-entry
        }
    }

    cout << endl << "---------------------------------------------------------------" << endl;
    cout << "Dear " << name << "," << endl << endl;
    cout << "Thank you for paying your tax ON TIME, you have chosen Plan " << planChoice << "!"<< endl;
    cout << "Remember that IR$ of Banana Republic is always here for you." << endl << endl;
    cout << "Best Regards, " << endl;
    cout << "IR$ Support Team" << endl;
    cout << "---------------------------------------------------------------" << endl;


    return 0;
}