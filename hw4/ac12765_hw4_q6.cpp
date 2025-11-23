/*
Question 6:
Write a	program	that asks the user to input	a positive integer n, and print	all	of the numbers	
from 1 to n that have more even	digits than	odd	digits.
For	example, if	n=30, the program should print:
2
4
6
8
20
22
24
26
28
*/

#include <iostream>
//using namespace std;

int main() {
    int n;
    int num, digit;
    int evencount, oddcount;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Please enter a positive integer." << std::endl;
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        evencount = 0, oddcount = 0;
        num = i;

        while (num > 0) {
            digit = num % 10;
            if (digit % 2 == 0) {
                evencount++;
            } else {
                oddcount++;
            }
            num /= 10;
        }

        if (evencount > oddcount) {
            std::cout << i << std::endl;
        }
    }

    return 0;
}