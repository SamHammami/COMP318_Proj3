/* --------------------------------- Wheaton College MA - Spring 2024 ---------------------------------*\
 * Comp 318, programming project 3
 * Sam Hammami '25
 * **********************************************
 * Thank you for the great semester, Prof. Tony!
 * I learned a lot and enjoyed the class.(Safe travel)
 * **********************************************
 */

#include "changeMaker.h"
#include <iostream>

using namespace std;

                /*------------------------------Main Function------------------------------*/
int main() {
    // Welcome message
    cout << endl << endl << "***     Welcome to the IR$ of Banana Republic!     ***" << endl << endl;

//    string name = "Poor Patrick"; //For testing purposes: Houssem .H, Poor Patrick, Rich Richard
    string name;
    cout << "Please enter your name below! " << endl;
    cout << "My Name is";
    getline(cin, name);

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
    cout << "* -------------------------- ***** ------------------------ *" << endl;
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