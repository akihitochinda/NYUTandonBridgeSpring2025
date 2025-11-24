/*
Question 4:
Write a program that reads from the user two positive integers, and prints the result of when we add, subtract, multiply, divide, div, and mod them.

Your program should interact with the user exactly as it shows in the following example:

Please enter two positive integers, separated by a space:
14 4
14 + 4 = 18
14 - 4 = 10
14 * 4 = 56
14 / 4 = 3.5
14 div 4 = 3
14 mod 4 = 2
*/

#include <iostream>
//using namespace std;

int main() {
    int a, b;
    std::cout << "Please enter two positive integers, separated by a space:\n";
    std::cin >> a >> b;

    std::cout << a << " + " << b << " = " << a + b << "\n";
    std::cout << a << " - " << b << " = " << a - b << "\n";
    std::cout << a << " * " << b << " = " << a * b << "\n";
    std::cout << a << " / " << b << " = " << static_cast<double>(a) / b << "\n";
    std::cout << a << " div " << b << " = " << a / b << "\n";
    std::cout << a << " mod " << b << " = " << a % b << "\n";

    return 0;
}