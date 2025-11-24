/*
Question 2:
Two strings are anagrams if the letters can be rearranged to form each other. For example,
“Eleven plus two” is an anagram of “Twelve plus one”. Each string contains one ‘v’, three ‘e’s,
two ‘l’s, etc.
Write a program that determines if two strings are anagrams. The program should not be case
sensitive and should disregard any punctuation or spaces.

Notes:
1.  Think how to break down your implementation to functions.
2.  Pay attention to the running time of your program. If each input string contains 𝑛
    characters, an efficient implementation would run in a linear time (that is Θ(𝑛)). 
*/

#include <iostream>
#include <string>
//using namespace std;


const int ALPHABET_SIZE = 26;

void getLetterCount(std::string str, int letterCountArr[]);
bool areAnagrams(std::string str1, std::string str2);

int main() {
    std::string str1, str2;

    std::cout << "Please enter the first string:" << std::endl;
    std::getline(std::cin, str1);

    std::cout << "Please enter the second string:" << std::endl;
    std::getline(std::cin, str2);

    if (areAnagrams(str1, str2)) {
        std::cout << "The strings are anagrams." << std::endl;
    } else {
        std::cout << "The strings are not anagrams." << std::endl;
    }

    return 0;
}

void getLetterCount(std::string str, int letterCountArr[]) {
    for (int i = 0; i < str.length(); i++) {
        char c = tolower(str[i]);
        if ('a' <= c && c <= 'z') {
            letterCountArr[c - 'a']++; // Increment the corresponding index which maps 'a' to index 0, 'b' to index 1, and so on up to 'z' at index 25
        }
    }
}

bool areAnagrams(std::string str1, std::string str2) {
    int letterCountArr1[ALPHABET_SIZE] = {0};
    int letterCountArr2[ALPHABET_SIZE] = {0};

    getLetterCount(str1, letterCountArr1);
    getLetterCount(str2, letterCountArr2);

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (letterCountArr1[i] != letterCountArr2[i]) {
            return false;
        }
    }
    return true;
}