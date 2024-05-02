#include <iostream>
#include "changeMaker.h"

using namespace std;

//test now
int main() {

    double amount;

    do {
        cout << "Enter amount in dollars (negative to exit): ";
        cin >> amount;
        if (amount < 0) break;

        int *A = greedyPlan(amount);

        cout << "Number of coins in Greedy Algorithm:\n";
        cout << "  1 cent: " << A[0] << endl;
        cout << "  7 cents: " << A[1] << endl;
        cout << "  30 cents: " << A[2] << endl;
        cout << "  84 cents: " << A[3] << endl;
        cout << "  235 cents: " << A[4] << endl;

        ChangePlan result = dynamicPlan(amount);

        cout << "Number of coins in Optimal Algorithm:\n";
        cout << "  1 cent: " << result.solution[0] << endl;
        cout << "  7 cents: " << result.solution[1] << endl;
        cout << "  30 cents: " << result.solution[2] << endl;
        cout << "  84 cents: " << result.solution[3] << endl;
        cout << "  235 cents: " << result.solution[4] << endl;
    } while (true);

    return 0;
}
