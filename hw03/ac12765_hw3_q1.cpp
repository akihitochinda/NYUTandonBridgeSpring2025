/*
Question 1:
Write a program that computes how much a customer has to pay after purchasing two items. The price is calculated according to the following rules:

Buy one get one half off promotion: the lower price item is half off.
If the customer is club card member, additional 10% off.
Inputs to the program include:

Two items' prices
Have club card or not (User enters 'Y' or 'y' for "yes"; 'N' or 'n' for "no")
Tax rate (User enters the percentage as a number; for example they enter 8.25 if the tax rate is 8.25)
Program displays:

Base price - the price before discounts and taxes
Price after discounts - the price before taxes but after buy one get one half off promotion and the member's discount, if applicable
Total price - the amount of money the customer has to pay (after taxes).

Your program should interact with the user exactly as it shows in the following example:
Enter price of first item: 10
Enter price of second item: 20
Does customer have a club card? (Y/N): y
Enter tax rate, e.g. 5.5 for 5.5% tax rate: 8.25

Base price: 30.0
Price after discounts: 22.5
Total price: 24.35625
*/

#include <iostream>
//using namespace std;

int main() {
    double item1, item2, taxrate;
    char clubcard;

    std::cout << "Enter price of first item: ";
    std::cin >> item1;
    std::cout << "Enter price of second item: ";
    std::cin >> item2;

    std::cout << "Does customer have a club card? (Y/N): ";
    std::cin >> clubcard;

    std::cout << "Enter tax rate, e.g. 5.5 for 5.5% tax rate: ";
    std::cin >> taxrate;

    double basePrice = item1 + item2;
    double discountPrice = (item1 < item2) ? ((item1 / 2) + item2) : (item1 + (item2 / 2));

    if (clubcard == 'Y' || clubcard == 'y') {
        discountPrice *= 0.9;
    }

    double totalPrice = discountPrice * (1 + taxrate / 100);

    std::cout << "Base price: " << basePrice << "\n";
    std::cout << "Price after discounts: " << discountPrice << "\n";
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(5);
    std::cout << "Total price: " << totalPrice << "\n";

    return 0;
}