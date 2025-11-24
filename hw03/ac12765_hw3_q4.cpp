/*
Question 4:
Define the following constants:

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

Write a program that asks the user to enter a Real number, then it asks the user to enter the method by which they want to round that number (floor, ceiling or to the nearest integer). The program will then print the rounded result.

Your program should interact with the user exactly as it shows in the following example:
Please enter a Real number: 
4.78
Choose your rounding method:
1. Floor round
2. Ceiling round
3. Round to the nearest whole number
2
5

Implementation requirements:

1. Use a switch statement.
2. You are not allowed to include and use the math library.
*/

#include <iostream>
//using namespace std;

int main() {
    const int FLOOR_ROUND = 1;
    const int CEILING_ROUND = 2;
    const int ROUND = 3;

    double number;
    int method;

    std::cout << "Please enter a Real number: ";
    std::cin >> number;

    std::cout << "Choose your rounding method:\n";
    std::cout << "1. Floor round\n";
    std::cout << "2. Ceiling round\n";
    std::cout << "3. Round to the nearest whole number\n";
    std::cin >> method;

    switch (method) {
        case FLOOR_ROUND:
            if (number >= 0) {
                std::cout << static_cast<int>(number) << std::endl;
            } else {
                std::cout << static_cast<int>(number) - 1 << std::endl;
            }
            break;
        case CEILING_ROUND:
            if (number > 0) {
                std::cout << static_cast<int>(number) + 1 << std::endl;
            } else {
                std::cout << static_cast<int>(number) << std::endl;
            }
            break;
        case ROUND:
            if (number >= 0) {
                if (number - static_cast<int>(number) >= 0.5) {
                    std::cout << static_cast<int>(number) + 1 << std::endl;
                } else {
                    std::cout << static_cast<int>(number) << std::endl;
                }
            } else {
                if (static_cast<int>(number) - number >= 0.5) {
                    std::cout << static_cast<int>(number) - 1 << std::endl;
                } else {
                    std::cout << static_cast<int>(number) << std::endl;
                }
            }
            break;
        default:
            std::cout << "Invalid method selected." << std::endl;
            break;
    }

    return 0;
}