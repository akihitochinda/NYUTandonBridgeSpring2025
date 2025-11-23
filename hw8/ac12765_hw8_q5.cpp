/*
Question 5:
Write a program that reads a person’s name in the following format:  
first name, then middle name or initial, and then last name.  
The program then outputs the name in the following format:  
Last_Name, First_Name Middle_Initial.  

For example, the input    
Mary Average User 
should produce the output:
User, Mary A.

The input Mary A. User 
should also produce the output:
User, Mary A.

Note that your program should work the same and place a period after the middle initial even if 
the input did not contain a period.

Hint: You may want to use three string variables rather than one large string variable for the 
input. You may find it easier to not use getline.
*/

#include <iostream>
#include <string>
//using namespace std;

int main() {
    std::string firstName, middleName, lastName, middleInitial;

    std::cout << "Please enter your name separated by a space(first name, middle name or initial, and last name.): ";
    std::cin >> firstName >> middleName >> lastName;

    middleInitial = middleName[0];

    std::cout << lastName << ", " << firstName << " " 
              << middleInitial << ".\n";

    return 0;
}