/*
Question 5:	
Write a program that asks the user to input a positive integer n, and prints a textual image of an 
hourglass made of 2n lines with asterisks. 
For example if n=4, the program should print:
*******
 *****
  ***
   *
   *
  ***
 *****
*******
*/

#include <iostream>
//using namespace std;

int main() {
    int n, i, j;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Please enter a positive integer." << std::endl;
        return 1;
    }

    for (i = 0; i < n; i++) { //Upper rows

        for (j = 0; j < i; j++) {
            std::cout << " ";
        }

        for (j = 0; j < 2 * (n - i) - 1; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    for (i = 1; i <= n; i++) { //Lower rows

        for (j = n - 1; j >= i; j--) {
            std::cout << " ";
        }

        for (j = 0; j < 2 * i - 1; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    return 0;
}