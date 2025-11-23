/*
Question 1:
Write a program that will read in a line of text and output the number of words in the line and
the number of occurrences of each letter.
Define a word to be any string of letters that is delimited at each end by either whitespace, a
period, a comma, or the beginning or end of the line.
You can assume that the input consists entirely of letters, whitespace, commas, and periods.
When outputting the number of letters that occur in a line, be sure to count upper and
lowercase versions of a letter as the same letter.
Output the letters in alphabetical order and list only those letters that do occur in the input line.

Your program should interact with the user exactly as it shows in the following example:
Please enter a line of text:
I say Hi.
3 words
1 a
1 h
2 i
1 s
1 y

Notes:
1.  Think how to break down your implementation to functions.
2.  Pay attention to the running time of your program. If the input line contains 𝑛 characters, an
    efficient implementation would run in a linear time (that is Θ(𝑛)).
*/

#include <iostream>
#include <string>
//using namespace std;


const int ALPHABET_SIZE = 26;

int getWordCount(std::string str);
void getLetterCount(std::string str, int arr[]);

int main() {
    std::string str;
    int letterCountArr[ALPHABET_SIZE] = {0};

    std::cout << "Please enter a line of text:" << std::endl;
    std::getline(std::cin, str);

    int wordCount = getWordCount(str);
    std::cout << wordCount << " " << "words" << std::endl;

    getLetterCount(str, letterCountArr);
    
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        char letter = 'a' + i; // Convert index to corresponding letter which maps 0 to 'a', 1 to 'b', ..., 25 to 'z'
        if (letterCountArr[i] != 0){
            std::cout << letterCountArr[i] << " " << letter << std::endl;
        }
    }

    return 0;
}

int getWordCount(std::string str) {
    int wordCount = 0;
    for (int i = 0; i <= str.length(); i++){ // is delimited at each end by either whitespace, a period, a comma, or the beginning or end of the line
        if (i == str.length() || str[i] == ' ' || str[i] == '.' || str[i] == ',') {
            if (i > 0 && (str[i - 1] != ' ' && str[i - 1] != '.' && str[i - 1] != ',')) {
                wordCount++;
            }
        }
    }
    return wordCount;
}

void getLetterCount(std::string str, int letterCountArr[]) {
    for (int i = 0; i < str.length(); i++) {
        char c = tolower(str[i]);
        if ('a' <= c && c <= 'z') {
            letterCountArr[c - 'a']++; // Increment the corresponding index which maps 'a' to index 0, 'b' to index 1, and so on up to 'z' at index 25
        }
    }
}