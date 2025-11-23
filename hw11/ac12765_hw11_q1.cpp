/*
Question 1:
Give a recursive implement to the following functions:
a.  void printTriangle(int n)
    This function is given a positive integer n, and prints a textual image of a right triangle
    (aligned to the left) made of n lines with asterisks.
    For example, printTriangle(4), should print:
    *
    **
    ***
    ****

b.  void printOppositeTriangles(int n)
    This function is given a positive integer n, and prints a textual image of a two opposite right
    triangles (aligned to the left) with asterisks, each containing n lines.
    For example, printOppositeTriangles(4), should print:
    ****
    ***
    **
    *
    *
    **
    ***
    ****

c.  void printRuler(int n)
    This function is given a positive integer n, and prints a vertical ruler of 2^n − 1 lines. Each line contains ‘-‘ marks as follows:
    ・  The line in the middle (1/2) of the ruler contains n ‘-‘ marks "
    ・  The lines at the middle of each half (1/4 and 3/4) of the ruler contains (n-1) ‘-‘ marks
    ・　The lines at the 1/8, 3/8, 5/8 and 7/8 of the ruler contains (n-2) ‘-‘ marks
    ・  And so on ...
    ・  The lines at the 1/2^k , 3/2^k , 5/2^k ,..., 2^k-1/2^k of the ruler contains 1 ‘-‘ mark

    For example, printRuler(4), should print (only the blue marks):
    -           1/16=   1/16
    --          2/16=   1/8
    -           3/16=   3/16
    ---         4/16=   1/4
    -           5/16=   5/16
    --          6/16=   3/8
    -           7/16=   7/16
    ----        8/16=   1/2
    -           9/16=   9/16
    --          10/16=  5/8
    -           11/16=  11/16
    ---         12/16=  3/4
    -           13/16=  13/16
    --          14/16=  7/8
    -           15/16=  15/16

Hints:
1.  Take for n=4: when finding print_ruler(4), try to think first what
    print_ruler(3) does, and how you can use it to print a ruler of size 4.
    Then, generally identify what print_ruler(n-1) is supposed to print, and use that
    in order to define how to print the ruler of size n.
2.  You may want to have more than one recursive call
3.  It looks much scarier than it actually is
*/

#include <iostream>
//using namespace std;

void printTriangle(int n);
void printOppositeTriangles(int n);
void printRuler(int n);

int main() {
    int n;

    std::cout << "Enter a positive integer for triangle: ";
    std::cin >> n;
    printTriangle(n);
    
    std::cout << "Enter a positive integer for opposite triangles: ";
    std::cin >> n;
    printOppositeTriangles(n);
    
    std::cout << "Enter a positive integer for ruler: ";
    std::cin >> n;
    printRuler(n);

    return 0;
}

void printTriangle(int n) {
    if (n == 1) { // Base case
        std::cout << '*' << std::endl;
    } else {
        printTriangle(n - 1); // Recursive call / When the base case is reached (n == 1), the function starts returning, and each previous call resumes with its own value of n.
        for (int i = 0; i < n; i++) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
}

void printOppositeTriangles(int n) {
    if (n == 1) { // Base case
       std::cout << '*' << std::endl;
       std::cout << '*' << std::endl;
    } else {
        for (int i = 0; i < n; i++) {
            std::cout << '*';
        }
        std::cout << std::endl;

        printOppositeTriangles(n - 1); // Recursive call, prints the upper half of the opposite triangles first, then returns to print the lower half

        for (int i = 0; i < n; i++) {
            std::cout << '*';
        }
        std::cout << std::endl;

    }
}

void printRuler(int n) {
    if (n == 1) { // Base case
        std::cout << '-' << std::endl;
    } else {
        printRuler(n - 1); // First recursive call, prints the upper half of the ruler
        for (int i = 0; i < n; i++) {
            std::cout << '-';
        }
        std::cout << std::endl;
        printRuler(n - 1); // Second recursive call, prints the lower half of the ruler / If printRuler(4) is called for the first call to print the upper half of the ruler, then finally it will return to the point of printRuler(3) again to print the lower half of the ruler.
    }

}