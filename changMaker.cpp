


#include "changeMaker.h"

using namespace std;

/**
 * Description: This function implements a greedy algorithm to make change for a given amount
 *              using a set of coin denominations. It returns the number of coins of each
 *              denomination required to make the change.
 * Parameters:  amount of type double - the amount of money to make change for.
 * Returns:     a pointer to an array of ints. The array contains the number of each type
 *              of coin required to make change for the given amount.
 */
int* greedyChangeMaker(double amount) {

    amount = roundToInt(amount);
    int n = 5;
    int *A = new int[n];

    while (amount != 0) {
        if (amount >= 235) {
            amount = amount - 235;
            A[4]++;
        }
        else if (amount >= 84) {
            amount = amount - 84;
            A[3]++;
        }
        else if (amount >= 30) {
            amount = amount - 30;
            A[2]++;
        }
        else if (amount >= 7) {
            amount = amount - 7;
            A[1]++;
        }
        else if (amount >= 1) {
            amount = amount - 1;
            A[0]++;
        }
    }

    return A;

};
/**
 * Description: This function implements a dynamic programming algorithm to find the
 *              minimum number of coins required to make change for a given amount using
 *              a set of coin denominations. It returns a ChangeStruct object that contains
 *              the minimum number of coins required, as well as the specific coin
 *              denominations that should be used to achieve that minimum.
 * Parameters:  amount of type double - the amount of money to make change for.
 * Returns:     a ChangeStruct object that contains the minimum number of coins required to
 *              make change for the given amount, as well as the specific coin denominations
 *              that should be used.
 */
ChangeStruct dynamicChangeMaker(double amount) {
    int cents = round(amount * 100);
    int coinValue[] = {1, 7, 30, 84, 235};
    int numCoins = sizeof(coinValue) / sizeof(coinValue[0]);

    ChangeStruct* memo = new ChangeStruct[cents + 1];
    memo[0].totalCoin = 0;

    for (int i = 1; i <= cents; i++) {
        memo[i].totalCoin = INT_MAX;
        for (int j = 0; j < numCoins; j++) {
            if (i >= coinValue[j] && memo[i - coinValue[j]].totalCoin + 1 < memo[i].totalCoin) {
                memo[i].totalCoin = memo[i - coinValue[j]].totalCoin + 1;
                for (int k = 0; k < numCoins; k++) {
                    memo[i].solution[k] = memo[i - coinValue[j]].solution[k];
                }
                memo[i].solution[j]++;
            }
        }
    }

    ChangeStruct result = memo[cents];
    delete[] memo;

    return result;
}

/**
 * Description: This function takes a decimal number num and rounds it to the nearest
 *              integer by multiplying it by 100, rounding to the nearest integer,
 *              and then dividing the result by 100. The resulting integer value
 *              is then returned.
 * Parameters:  num of type double - a decimal number to be rounded to the nearest integer.
 * Returns:     an int representing the rounded integer value of the input num.
 */

int roundToInt (double num) {
        int amount = round(num * 100); // convert amount to cents
        return amount;
}
