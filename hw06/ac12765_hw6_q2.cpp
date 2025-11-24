/*
Question 2:
Write a	program	that, prints a ‘pine tree’ consisting of triangles of increasing sizes,	filled	
with a character (eg. ‘*’ or ’+’ or	‘$’	etc).	
Your program should	interact with the user to read the number of triangles in the tree and	
the	character filling the tree.

Your implementation	should include the following functions:
a. void printShiftedTriangle(int n, int m, char symbol)
It prints an n-line	triangle, filled with symbol characters, shifted m spaces from the left	
margin.

For	example, if	we call	printShiftedTriangle(3, 4, `+`), the expected output	
is:
      +
     +++
    +++++
Left margin 4 spaces 

b. void printPineTree(int n, char symbol)
It prints a	sequence of	n triangles	of increasing sizes	(the smallest triangle is a	2-line	
triangle), which form the shape	of a pine tree.	The	triangles are filled with the symbol
character.	
For	example, if	we call	printPineTree(3, `#`), the expected	output is:
   #
  ###
   #
  ###
 #####
   #
  ###
 #####
#######
*/

#include <iostream>
//using namespace std;

void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);

int main() {
    int num;
    char symbol;

    std::cout << "Please enter the number of triangles in the tree: ";
    std::cin >> num;
    std::cout << "Please enter the character filling the tree: ";
    std::cin >> symbol;

    printPineTree(num, symbol);
    
    return 0;
}

//a. void printShiftedTriangle(int n, int m, char symbol)
void printShiftedTriangle(int n, int m, char symbol) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cout << ' ';
        }
        for (int k = 1; k <= n - i; k++) {
            std::cout << ' ';
        }
        for (int l = 1; l <= 2 * i - 1; l++) {
            std::cout << symbol;
        }

        std::cout << std::endl;
    }
}

//b. void printPineTree(int n, char symbol)
void printPineTree(int n, char symbol) {
    for (int i = 1; i <= n; i++) {
        printShiftedTriangle(i + 1, n - i, symbol);
    }
}