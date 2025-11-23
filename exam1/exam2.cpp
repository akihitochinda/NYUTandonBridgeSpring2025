/*
Question 20
    Consider the following definition:
    Definition: A traditional die/dice is a cube with each of its six faces marked with a different number of
dots (pips) from one to six. When thrown or rolled, the die/dice comes to rest showing a random integer
from one to six on its upper surface, with each value being equally likely.
    For this program, the user will enter a number between 1 and 6 to simulate the rolling event. If the
user types 1, we will consider that the user has rolled the dice and the face with one dot (pip) appeared.
If the user types 2, we will consider that the user has rolled the dice and the face with two dots (pips) has
appeared, and so on.
    Write a program that reads from the user a sequence of numbers between 1 and 6 and prints the
following statistics:

Total number of times of Faces with even numbered dots appeared:
Number of times Face with one dot appeared:
Number of times Face with three dots appeared:
Number of times Face with six dots appeared:

Implementation requirement:
1. The user should enter their numbers, each one in a separate line, and type -1 to indicate the end of
the input.
2. You are not allowed to use C++ syntactic features that were not covered in the Bridge program so far.
3. Faces with even numbered dots are Face with two dots, Face with four dots, and Face with six dots.
Your program should interact with the user exactly the same way, as demonstrated below:

Execution example:
Please enter a sequence of numbers in between 1 and 6, each one in a separate line.
End your sequence by typing -1:
1
5
5
1
3
5
6
1
2
3
1
2
4
5
6
2
-1

Total number of times Faces with even numbered dots appeared: 6
Number of times Face with one dot appeared: 4
Number of times Face with three dots appeared: 2
Number of times Face with six dots appeared: 2
*/

#include <iostream>
//using namespace std;

int main() {
    int face, evenCount = 0, oneCount = 0, threeCount = 0, sixCount = 0;

    std::cout << "Please enter a sequence of numbers in between 1 and 6, each one in a separate line.\n";
    std::cout << "End your sequence by typing -1:\n";

    while (true) {
        std::cin >> face;
        if (face == -1) {
            break;
        }
        if (face < 1 || 6 < face) {
            std::cout << "Please enter a number between 1 and 6.\n";
            continue;
        }
        if (face % 2 == 0) {
            evenCount++;
        }
        if (face == 1) {
            oneCount++;
        }
        if (face == 3) {
            threeCount++;
        }
        if (face == 6) {
            sixCount++;
        }
    }

    std::cout << "Total number of times Faces with even numbered dots appeared: " << evenCount << "\n";
    std::cout << "Number of times Face with one dot appeared: " << oneCount << "\n";
    std::cout << "Number of times Face with three dots appeared: " << threeCount << "\n";
    std::cout << "Number of times Face with six dots appeared: " << sixCount << "\n";

    return 0;
}