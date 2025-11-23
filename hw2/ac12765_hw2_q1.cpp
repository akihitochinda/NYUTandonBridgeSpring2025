/*
Question 1:
Write a program that asks the user to enter a number of quarters, dimes, nickels, and pennies, then outputs the monetary value of the coins in the format of dollars and remaining cents.

Your program should interact with the user exactly as shown in the following example:
Please enter number of coins:
# of quarters: 13
# of dimes: 4
# of nickels: 11
# of pennies: 17
The total is 4 dollars and 37 cents.
*/

#include <iostream>
//using namespace std;

int main() {
    int quarters, dimes, nickels, pennies;
    int total, dollars, cents;

    std::cout << "Please enter number of coins:" << std::endl;
    std::cout << "# of quarters: ";
    std::cin >> quarters;
    std::cout << "# of dimes: ";
    std::cin >> dimes;
    std::cout << "# of nickels: ";
    std::cin >> nickels;
    std::cout << "# of pennies: ";
    std::cin >> pennies;

    total = (quarters * 25) + (dimes * 10) + (nickels * 5) + pennies;
    dollars = total / 100;
    cents = total % 100;

    std::cout << "The total is " << dollars << " dollars and " << cents << " cents." << std::endl;

    return 0;
}