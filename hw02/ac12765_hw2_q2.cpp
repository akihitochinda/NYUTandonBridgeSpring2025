/*
Question 2:
Write a program that prompts the user to enter an amount of money in the format of dollars and remaining cents. The program should then calculate and print the minimum number of coins (quarters, dimes, nickels, and pennies) that are equivalent to the given amount.

Hint: In order to find the minimum number of coins, first find the maximum number of quarters that fit in the given amount, then Find the maximum number of dimes that fit in the remaining amount, and so on.

Your program should interact with the user exactly as shown in the following example:
Please enter your amount in the format of dollars and cents separated by a space:
4 37
4 dollars and 37 cents are:
17 quarters, 1 dimes, 0 nickels and 2 pennies
*/

#include <iostream>
//using namespace std;

int main() {
    int dollars, cents;
    int total, quarters, dimes, nickels, pennies;

    std::cout << "Please enter your amount in the format of dollars and cents separated by a space:" << std::endl;
    std::cin >> dollars >> cents;

    total = (dollars * 100) + cents;

    quarters = total / 25;
    total %= 25;

    dimes = total / 10;
    total %= 10;

    nickels = total / 5;
    total %= 5;

    pennies = total;

    std::cout << dollars << " dollars and " << cents << " cents are:" << std::endl;
    std::cout << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels and " << pennies << " pennies" << std::endl;

    return 0;
}