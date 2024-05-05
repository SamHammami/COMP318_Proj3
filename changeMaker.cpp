
#include "changeMaker.h"


/*--------------------------------Logic (Greedy & Dynamic) Approach------------------------------------*/

                                /*------- Greedy Approach -------*/
/* --- array<int, 6> greedyPlan(...) ---
 * Description:
 * - This function calculates the greedy plan for the given tax amount.
 *
 * Parameters:
 * - int taxAmount: The tax amount due
 * - const array<int, 6> &denominations: The array of denominations
 *
 * Returns:
 * - array<int, 6>: The greedy plan
 */

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

/* --- ChangePlan dynamicPlan(...) ---
 * Description:
 * - This function calculates the dynamic plan for the given tax amount.
 *
 * Parameters:
 * - int taxAmount: The tax amount due
 * - array<int, 6> denominations: The array of denominations
 *
 * Returns:
 * - ChangePlan: The dynamic plan
 */

ChangePlan dynamicPlan(int taxAmount, const array<int, 6> &denominations) {

//     Array of denominations
//    const int denominations[6] = {95000, 32001, 5001, 701, 101, 1};

    // Vector of ChangePlan objects
    vector<ChangePlan> dynamic(taxAmount + 1);

    // Base case
    dynamic[0].totalBills = 0;
    dynamic[0].plan.fill(0);

    for (int i = 1; i <= taxAmount; ++i) {
        dynamic[i].totalBills = INT_MAX;

        for (int j = 0; j < 6; ++j) {

            if (i >= denominations[j]) {
                ChangePlan newSolution = dynamic[i - denominations[j]];
                newSolution.totalBills++;
                newSolution.plan[j]++;

                if (newSolution.totalBills < dynamic[i].totalBills) {
                    dynamic[i] = newSolution;
                }
                // Helper variable to calculate the total number of bills
            }
            //dynamic[i].totalBills += dynamic[i - denominations[j]].totalBills;
        }
        //dynamic[i].totalBills = min(dynamic[i].totalBills, dynamic[i - denominations[j]].totalBills);
    }

    return dynamic[taxAmount]; // Return the plan for the given tax amount (dynamic)
}


/*--------------------------------Display (Greedy) & (Dynamic) Approach------------------------------------*/

                                /*------- Greedy Approach -------*/
/* --- void displayGreedyApproach(...) ---
 * Description:
 * - This function displays the greedy approach for the given tax amount.
 *
 * Parameters:
 * - int taxAmount: The tax amount due
 * - const array<int, 6> &denominations: The array of denominations
 *
 * Returns:
 * - None
 */

void displayGreedyApproach(int taxAmount, const array <int, 6> &denominations) {

    // Get the greedy plan
    array<int, 6> greedyResult = greedyPlan(taxAmount, denominations);

    // Start displaying the greedy result
    cout << "Plan 1: The Greedy Approach" << endl;
    cout << "Tax Due: $" << taxAmount << endl;
    cout << setw(16) << " " ; //Spacing to push table
    cout << left << setw(14) << "Bills" << setw(22) << "Num" << "Subtotal" << endl;

    int subtotalGreedy = 0;
    string storeGreedyBills; // String to store the total number of bills
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
/* --- void displayDynamicApproach(...) ---
 * Description:
 * - This function displays the dynamic approach for the given tax amount.
 *
 * Parameters:
 * - int taxAmount: The tax amount due
 * - const array<int, 6> &denominations: The array of denominations
 *
 * Returns:
 * - None
 */
void displayDynamicApproach(int taxAmount, const array <int, 6> &denominations) {

    // Get the dynamic plan
    ChangePlan dynamicResult = dynamicPlan(taxAmount, denominations);

    // Start displaying the dynamic result
    cout << "Plan 2: The Dynamic Programming Approach" << endl;
    cout << "Tax Due: $" << taxAmount << endl;
    cout << setw(16) << " "; //Spacing to push table
    cout << left << setw(14) << "Bills" << setw(22) << "Num" << "Subtotal" << endl;

    int subtotalDynamic = 0;
    string storeDynamicBills;

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
            storeDynamicBills += " + ";
        }
        storeDynamicBills += to_string(num);
        cout << " $" << subtotalDynamic << endl;

    }
    // Display the total number of bills one by one (Dynamic)
    cout << endl << "Total number of bills needed: " << storeDynamicBills << " = " << dynamicResult.totalBills << endl;
}