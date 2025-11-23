/*
Question 3:
Suppose John and Bill worked for some time and we want to calculate the total time both of them worked. Write a program that reads number of days, hours, minutes each of them worked, and prints the total time both of them worked together as days, hours, minutes.

Hint: Try to adapt the elementary method for addition of numbers to this use.

Your program should interact with the user exactly as it shows in the following example:

Please enter the number of days John has worked: 2
Please enter the number of hours John has worked: 12
Please enter the number of minutes John has worked: 15

Please enter the number of days Bill has worked: 3
Please enter the number of hours Bill has worked: 15
Please enter the number of minutes Bill has worked: 20

The total time both of them worked together is: 6 days, 3 hours and 35 minutes.
*/

#include <iostream>
//using namespace std;

int main() {
    int days_john, hours_john, minutes_john;
    int days_bill, hours_bill, minutes_bill;
    int total_days, total_hours, total_minutes;

    std::cout << "Please enter the number of days John has worked: ";
    std::cin >> days_john;
    std::cout << "Please enter the number of hours John has worked: ";
    std::cin >> hours_john;
    std::cout << "Please enter the number of minutes John has worked: ";
    std::cin >> minutes_john;

    std::cout << "Please enter the number of days Bill has worked: ";
    std::cin >> days_bill;
    std::cout << "Please enter the number of hours Bill has worked: ";
    std::cin >> hours_bill;
    std::cout << "Please enter the number of minutes Bill has worked: ";
    std::cin >> minutes_bill;

    total_minutes = minutes_john + minutes_bill;
    total_hours = hours_john + hours_bill + (total_minutes / 60);
    total_days = days_john + days_bill + (total_hours / 24);

    total_minutes %= 60;
    total_hours %= 24;

    std::cout << "The total time both of them worked together is: "
              << total_days << " days, "
              << total_hours << " hours and "
              << total_minutes << " minutes." << std::endl;

    return 0;
}