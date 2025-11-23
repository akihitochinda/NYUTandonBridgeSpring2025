/*
Question 2:
Consider the following definitions:
a.  A proper divisors of a positive integer (≥ 2) is any of its divisors excluding the number itself.
    For example, the proper divisors of 10 are: 1, 2 and 5.
b.  A perfect number is a positive integer (≥ 2) that is equal to the sum of its proper divisors.
    For example, 6 and 28 are perfect numbers, since:
    6 = 1 + 2 + 3
    28 = 1 + 2 + 4 + 7 + 14
    Background of perfect numbers: https://en.wikipedia.org/wiki/Perfect_number
c.  Amicable numbers are two different positive integer (≥ 2), so related that the sum of the
    proper divisors of  each is equal to the other number.
    For example, 220 and 284 are amicable numbers, since:
    284 = 1 + 2 + 4 + 5 + 10 + 11 + 20 + 22 + 44 + 55 + 110
    (proper divisors of 220)
    220 = 1 + 2 + 4 + 71 + 142
    (proper divisors of 284)
    Background of amicable numbers: https://en.wikipedia.org/wiki/Amicable_numbers

a.  Write a function:
    void analyzeDividors(int num, int& outCountDivs, int& outSumDivs)
    The function takes as an input a positive integer num (≥ 2), and updates two output
    parameters with the number of num's proper divisors and their sum.
    For example, if this function is called with num=12, since 1, 2, 3, 4 and 6 are 12s proper
    divisors, the function would update the output parameters with the numbers 5 and 16.

    Note: Pay attention to the running time of your function. An efficient implementation would
    run in Θ(√𝑛𝑢𝑚)

b.  Use the function you wrote in section (a), to implement the function:
    bool isPerfect(int num)
    This functions is given positive integer num (≥ 2), and determines if it is perfect number or
    not.

c.  Use the functions you implemented in sections (a) and (b), to write a program that reads
    from the user a positive integer M (≥ 2), and prints:
    •   All the perfect numbers between 2 and M.
    •   All pairs of amicable numbers that are between 2 and M (both numbers must be in the
        range).
    Note: Pay attention to the running time of your implementation. An efficient algorithm for
    this part would call analyzeDividors Θ(𝑀) times all together.
*/

#include <iostream>
#include <cmath>
//using namespace std;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);

int main() {
    int M;
    int countPerfect = 0;
    int countAmicable = 0;
    std::cout << "Enter a positive integer M (≥ 2): ";
    std::cin >> M;

    if (M < 2) {
        std::cerr << "A number must be greater than or equal to 2.\n";
        return 1;
    }

    std::cout << "All the perfect numbers between 2 and " << M << ": ";
    for (int i = 2; i <= M; i++) {
        if (isPerfect(i)) {
            std::cout << i << " ";
            countPerfect++;
        }
    }
    if (countPerfect == 0) {
        std::cout << "None";
    }

    std::cout << "\n";

    std::cout << "All pairs of amicable numbers that are between 2 and " << M << ": ";
    for (int i = 2; i <= M; i++) {

        int countDivs, sumDivs;
        analyzeDividors(i, countDivs, sumDivs); // Get the divisors of the first number
        
        if (i < sumDivs && sumDivs <= M) { // Check only pairs where the second number is greater
            
            int otherNum = sumDivs;
            int otherCountDivs, otherSumDivs;
            analyzeDividors(otherNum, otherCountDivs, otherSumDivs); // Get the divisors of the second number
            
            if (otherSumDivs == i) {
                std::cout << "(" << i << ", " << otherNum << ") ";
                countAmicable++;
            }
        }
    }
    if (countAmicable == 0) {
        std::cout << "None";
    }

    std::cout << "\n";

    return 0;
}

void analyzeDividors(int num, int &outCountDivs, int &outSumDivs) {
    outCountDivs = 0;
    outSumDivs = 0;

    for (int i = 1; i <= sqrt(num); i++) { // Loop from 1 to the square root of num
        if (num % i == 0) {
            if (i < num) { // Proper divisor condition for perfect numbers
                outCountDivs++;
                outSumDivs += i;
            }
            
            int otherDivisor = num / i; // Find the corresponding divisor above the square root of num
            if (otherDivisor < num && otherDivisor != i) { // Avoid counting the number itself and duplicates
                outCountDivs++;
                outSumDivs += otherDivisor;
            }
        }
    }
}

bool isPerfect(int num) {
    int countDivs, sumDivs;
    analyzeDividors(num, countDivs, sumDivs); // Get the divisors of the current number

    return (sumDivs == num); // Check if the sum of proper divisors equals the number itself
}