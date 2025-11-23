/*
Question 2: Write a program that:

Asks the user for their name.
Asks the user to input their graduation year.
Asks the user to input the current year.
Assume the student is in a four-year undergraduate program. Display the current status the student is in. Possible statuses include: not in college yet, freshman, sophomore, junior, senior, graduated.

Note: If graduation year equals current year, status is ‘Graduated’; if graduation year is 5 years after current year, status is ‘Freshman’, etc.

Your program should interact with the user exactly as it shows in the following example:
Please enter your name: Jessica
Please enter your graduation year: 2019
Please enter current year: 2015
Jessica, you are a Freshman
*/

#include <iostream>
#include <string>
//using namespace std;

int main() {
    std::string name;
    int graduationyear;
    int currentyear;

    std::cout << "Please enter your name: ";
    std::getline(std::cin, name);

    std::cout << "Please enter your graduation year: ";
    std::cin >> graduationyear;

    std::cout << "Please enter current year: ";
    std::cin >> currentyear;

    if (graduationyear == currentyear) {
        std::cout << name << ", you are Graduated" << std::endl;
    } else if (graduationyear == currentyear + 1) {
        std::cout << name << ", you are a Senior" << std::endl;
    } else if (graduationyear == currentyear + 2) {
        std::cout << name << ", you are a Junior" << std::endl;
    } else if (graduationyear == currentyear + 3) {
        std::cout << name << ", you are a Sophomore" << std::endl;
    } else if (graduationyear == currentyear + 4) {
        std::cout << name << ", you are a Freshman" << std::endl;
    } else {
        std::cout << name << ", you are not in college yet" << std::endl;
    }

    return 0;
}