/*
Question 6:
Write a program that reads in a line of text and outputs the line with all the digits in all integer 
numbers replaced with 'x'.  
Please enter a line of text:  
My userID is john17 and my 4 digit pin is 1234 which is secret 
My userID is john17 and my x digit pin is xxxx which is secret 

Notes: 
1.  If a digits is part of a word, then the digit is not changed to an 'x'. For example, john17 is 
    NOT changed to johnxx.  
2.  You may assume that the text entered by the user will contain only letters (upper case or 
    lower case), digits and spaces. 
3.  Think how to break down your implementation to functions.
*/

#include <iostream>
#include <string>
//using namespace std;

void replaceDigitsWithX(std::string &text);

int main() {
    std::string inputText;

    std::cout << "Please enter a line of text: ";
    std::getline(std::cin, inputText);

    replaceDigitsWithX(inputText);

    std::cout << inputText << std::endl;

    return 0;
}

void replaceDigitsWithX(std::string &text) {
    for (int start = 0, end = 0; end <= text.length(); end++) {
        if (end == text.length() || text[end] == ' ') {
            std::string word = text.substr(start, end - start);
            bool allDigits = true;
            if (word.length() > 0) {
                for (char c : word) {
                    if (!isdigit(static_cast<unsigned char>(c))) {
                        allDigits = false;
                        break;
                    }
                }
                if (allDigits) {
                    for (int i = start; i < end; i++) {
                        text[i] = 'x';
                    }
                }
            }

            start = end + 1;
        }
    }
}