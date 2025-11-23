/*
Question 3:
Write a program that does the following:

Ask user to input three Real numbers a, b and c. They represent the parameters of a quadratic equation ax² + bx + c = 0
Classify to one of the following:
 - 'Infinite number of solutions' (for example, 0x² + 0x + 0 = 0 has infinite number of solutions)
 - 'No solution' (for example, 0x² + 0x + 4 = 0 has no solution)
 - 'No real solution' (for example, x² + 4 = 0 has no real solutions)
 - 'One real solution'
 - 'Two real solutions'
In cases there are 1 or 2 real solutions, also print the solutions.

Notes:
1. If a ≠ 0 and there are real solutions to the equation, you can get these solutions using the following formula:
x1,2 = −b ± sqrt(b² −4ac) / 2a

The number of solutions depends on whether (b² −4ac) is positive, zero, or negative.

2. In order to calculate the square root of a number (of type double), you should call the sqrt function located in the cmath library.

Follow this syntax as demonstrated in the code below:
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x = 2.0;
    double sqrtResult;

    sqrtResult = sqrt(x);
    cout << "sqrtResult=" << sqrtResult << endl;
    
    return 0;
}
Note that you first need to include the cmath library, and then you can call the sqrt function, passing the argument that you want to calculate the square root of, enclosed in parentheses.

Your program should interact with the user exactly as it shows in the following example:
Please enter value of a: 1
Please enter value of b: 4
Please enter value of c: 4

This equation has a single real solution x=-2.0
*/

#include <iostream>
#include <cmath>
//using namespace std;

int main() {
    double a, b, c;
    std::cout << "Please enter value of a: ";
    std::cin >> a;
    std::cout << "Please enter value of b: ";
    std::cin >> b;
    std::cout << "Please enter value of c: ";
    std::cin >> c;

    if (a == 0 && b == 0 && c == 0) {
        std::cout << "This equation has infinite number of solutions." << std::endl;
    } else if (a == 0 && b == 0) {
        std::cout << "This equation has no solution." << std::endl;
    } else {
        double discriminant = b * b - 4 * a * c;
        if (discriminant > 0) {
            double x1 = (-b + sqrt(discriminant)) / (2 * a);
            double x2 = (-b - sqrt(discriminant)) / (2 * a);
            std::cout << "This equation has two real solutions x1=" << x1 << ", x2=" << x2 << std::endl;
        } else if (discriminant == 0) {
            double x = -b / (2 * a);
            std::cout << "This equation has a single real solution x=" << x << std::endl;
        } else {
            std::cout << "This equation has no real solution." << std::endl;
        }
    }

    return 0;
}