/*
Question 4:
Write two versions of a program that reads a sequence of positive integers from the user, 
calculates their geometric mean, and print the geometric mean. 
Notes: 
1. In mathematics, geometric mean of a dataset {a1, a2, a3 … , an} containing positive 
numbers, is given by: n√a1 ∙ a2 ∙ a3 ∙∙∙ an. 
For example, the geometric mean of 2, 9 and 12 is equal to 6 (³√2 ∙ 9 ∙ 12 = 6).
2. In order to calculate the n-th root of a number,	you	should call	the	pow function, located	
in the cmath library.	

Your two versions should read the integer sequence in two ways: 
a) First read the length of the sequence.
For example, an execution would look like:
Please enter the length of the sequence: 3
Please enter your sequence: 
1
2
3
The geometric mean is: 1.8171

b) Keep reading the numbers until -1 is entered.
For example, an execution would look like:
Please enter a non-empty sequence of positive integers, each one in a separate line. End your 
sequence by typing -1:
1
2
3
-1
The geometric mean is: 1.8171
*/

#include <iostream>
#include <cmath>
//using namespace std;

int main() {
    int n;
    double product = 1.0;
    double geometric_mean;

    std::cout << "section a" << std::endl;
    std::cout << "Please enter the length of the sequence: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Please enter a positive integer." << std::endl;
        return 1;
    }

    std::cout << "Please enter your sequence: " << std::endl;
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        if (num <= 0) {
            std::cout << "Please enter positive integers." << std::endl;
            return 1;
        }
        product *= num;
    }

    geometric_mean = pow(product, 1.0 / n);
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(4);
    std::cout << "The geometric mean is: " << geometric_mean << std::endl;

    std::cout << "section b" << std::endl;
    product = 1.0;
    int count = 0;

    std::cout << "Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1:" << std::endl;
    
    while (true) {
        int num;
        std::cin >> num;

        if (num == -1) {
            break;
        }

        if (num <= 0) {
            std::cout << "Please enter positive integers." << std::endl;
            return 1;
        }

        product *= num;
        count++;
    }

    geometric_mean = pow(product, 1.0 / count);
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(4);
    std::cout << "The geometric mean is: " << geometric_mean << std::endl;

    return 0;
}