/*
Question 19
    Write a program that reads a positive odd integer, n, and prints a shape of n lines consisting of asterisks
(*) as follows:
1st line: print 1 asterisk
2nd line: print 3 asterisks
3rd line: print 5 asterisks
...
...
...
(n - 1)th line: print 2n - 3 asterisks
n th line: print 2n - 1 asterisks

    Your program should interact with the user exactly as demonstrated in the following three execution
examples:

Execution example 1:
Please enter a positive odd integer:
3
*
***
*****

Execution example 2:
Please enter a positive odd integer:
7
*
***
*****
*******
*********
***********
*************

Execution example 3:
Please enter a positive odd integer:
5
*
***
*****
*******
*********
*/

#include <iostream>
//using namespace std;

int main() {
    int n;
    std::cout << "Please enter a positive odd integer:\n";
    std::cin >> n;

    if (n <= 0 || n % 2 == 0) {
        std::cout << "Please enter a positive odd integer.\n";
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 2 * i - 1; j++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }

    return 0;
}