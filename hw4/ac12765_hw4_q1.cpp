/*
Question 1:	
Write two versions of a	program	that reads a positive integer n, and prints	the	first n even numbers.	
    a) In the first, use a while loop.	
    b) In the second, use a	for loop.	

Each section should	interact with the user exactly as it shows in the following	example:
Please enter a positive	integer: 3
2
4
6
*/

#include <iostream>
//using namespace std;

int main() {
    int n;
    std::cout << "Please enter a positive integer: ";
    std::cin >> n;

    // while loop
    int i = 1;
    std::cout << "section a" << std::endl;
    while (i <= n) {
        std::cout << i * 2 << std::endl;
        i++;
    }

    // for loop
    std::cout << "section b" << std::endl;
    for (int j = 1; j <= n; j++) {
        std::cout << j * 2 << std::endl;
    }

    return 0;
}