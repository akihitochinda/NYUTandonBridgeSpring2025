/*
Question 3:
The number e is an important mathematical constant that is the base of the natural logarithm. e
also arises in the study of compound interest, and in many other applications. 
Background of e: https://en.wikipedia.org/wiki/E_(mathematical_constant)

e can be calculated as the sum of the infinite series:
e = 1 + 1/1! + 1/2! + 1/3! + 1/4! + ⋯

The value of e is approximately equal to 2.71828. We can get an approximate value of e, by 
calculating only a partial sum of the infinite sum above (the more addends we add, the better 
approximation we get).

Implement the function:
double eApprox(int n)
This function is given a positive integer n, and returns an approximation of e, calculated by the 
sum of the first (n+1) addends of the infinite sum above.

To test your function use the following main:
int main() {
    cout.precision(30);

    for (int n = 1; n <= 15; n++) {
    cout<<"n = "<<n<<'\t'<<eApprox(n)<<endl;
    }
    
    return 0;
}

Notes:
1. Pay attention to the running time of eApprox. An efficient implementation would run in 
Θ(n).
2. Since the values of the factorials will grow to be very large, use a variable of type double
to store them.
*/

#include <iostream>
//using namespace std;

double eApprox(int n);

int main() {
    std::cout.precision(30);

    for (int n = 1; n <= 15; n++) {
        std::cout << "n = " << n << '\t' << eApprox(n) << std::endl;
    }
    
    return 0;
}

double eApprox(int n) {
    double sum = 1.0;
    double factorial = 1.0;

    for (int i = 1; i <= n; ++i) {
        factorial *= i;
        sum += 1.0 / factorial;
    }

    return sum;
}