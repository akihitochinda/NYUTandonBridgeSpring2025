/*
Make a hollowed-out diamond made uo of in-order alphabet letters. An example is below when n = 5:
    a
   b b
  c   c
 d     d
e       e
 d     d
  c   c
   b b
    a
 */

#include <iostream>
using namespace std;

int main() {
    int userInput = 7;
    char letter = 'a';
    char space = ' ';

    int outsideSpaceLimit = userInput - 1;
    int insideSpaceLimit = 0;

    for (int i = 1; i < (userInput * 2); i++) { // loop for the number of rows
        // outside spaces
        for (int j = 0; j < outsideSpaceLimit; j++) { // loop for the number of spaces
            cout << space;
        }
        // first letter

        cout << letter;

        // inside spaces
        for (int j = 1; j < insideSpaceLimit; j++) { // loop for the number of spaces
            cout << space;
        }

        // second letter
        if (i != 1 && i != ((userInput * 2) - 1)) { // avoid printing the same letter twice on the first and last row
            cout << letter;
        }

        if (i < userInput) { // upper half of the diamond
            letter++;
            insideSpaceLimit += 2;
            outsideSpaceLimit--;
        }
        else { // lower half of the diamond
            letter--;
            insideSpaceLimit -= 2;
            outsideSpaceLimit++;
        }

        cout << endl;
    }

    return 0;
}