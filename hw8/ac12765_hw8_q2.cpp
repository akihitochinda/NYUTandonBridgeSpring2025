/*
Question 2:
A palindrome is a word, which reads the same backward or forward. For example, noon, civic, 
radar, level, rotor, kayak, reviver, racecar, redder, madam, and refer are all palindromes. 
a.  Implement a function: 
    bool isPalindrome(string str) 
    This function is given a string str containing a word, and returns true if and only if str is 
    a palindrome. 

b.  Write a program that reads a word from the user and announces to the user if it is a 
    palindrome or not. 
    Your program should interact with the user exactly as it shows in the following example: 
    Please enter a word: level 
    level is a palindrome
*/

#include <iostream>
using namespace std;
#include <string>

bool isPalindrome(string str);

int main() {
    string str;
    cout << "Please enter a word: ";
    cin >> str;

    if (isPalindrome(str)) {
        cout << str << " is a palindrome" << endl;
    } else {
        cout << str << " is not a palindrome" << endl;
    }

    return 0;
}

bool isPalindrome(string str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false; // Not a palindrome
        }
        left++;
        right--;
    }

    return true; // Is a palindrome

}