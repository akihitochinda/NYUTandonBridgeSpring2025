/*
Question 3:
Write a program that reads from the user a positive integer (in a decimal representation), and 
prints its binary (base 2) representation.

Your program should	interact with the user exactly as it shows in the following	example:
Enter decimal number:
76
The	binary representation of 76	is 1001100

Implementation Requirements:
1. You are supposed to implement the algorithm that converts to base 2. You should not use 
   any string or special cout functionalities to make the conversion. 
2. You are not allowed to use arrays.
*/

#include <iostream>
//#include <string>
//using namespace std;

int main() {
    int input_number;
    int output_number;
    int binString = 0;
    int base = 1;
    //std::string binString = ""; //output binary string

    //to_string(1) ---> "1"
    //to_string(0) ---> "0"
    // you can use string concatenation (+) operator
    // "1" + "0" = "10"

    std::cout << "Enter decimal number:\n";
    std::cin >> input_number;

    //if (input_number <= 0) {
    if (input_number < 0) {
        std::cout << "Please enter a positive number.\n";
        return 1;
    }

    output_number = input_number;

    while (output_number > 0) {
        int remainder = output_number % 2;
        binString += remainder * base;
        //binString = std::to_string(remainder) + binString;
        output_number /= 2;
        base *= 10;
    }

    std::cout << "The binary representation of " << input_number << " is " << binString << "\n";

    return 0;
}