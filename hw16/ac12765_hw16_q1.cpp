/*
Homework 16: Stacks & Queues
    Part 1. Implement a symbol balance checker function for the Pascal programming
language. Pascal allows for the following pairs: {}, (), [], begin end . All programs will begin with
the word "begin" and end with the word "end". Your function should receive an ifstream object
which is already open and will return true, all of the symbols match, or false, they do not. You
do not have to worry about comments in the program but you do have to avoid other parts of the
program's code such as assignment statements (x=y) and other expressions. Example:

begin [{}][] end        returns True
begin [{}(]) end        returns False

Please submit a full program for this like with your previous assignments; with a main function to
show that your function works.
*/

#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

// Symbol balance checker for Pascal, including begin/end blocks
bool isBalanced(ifstream& inFile) {
    stack<string> s; // Stack to keep track of opening symbols and Pascal blocks
    string line;

    while (getline(inFile, line)) { // Read the file line by line
        istringstream iss(line); // Use istringstream to tokenize the line
        string token;
        while (iss >> token) { // Tokenize by whitespace to catch "begin" and "end"
            // Handle Pascal block keywords
            if (token == "begin") {
                s.push("begin");
            } else if (token == "end") {
                if (s.empty() || s.top() != "begin") return false; // Check if there's a matching "begin" for "end"
                s.pop(); // Pop the matching "begin" for "end"
            }
            // Check each character in the token for symbol pairs
            for (char c : token) {
                if (c == '{' || c == '(' || c == '[') {
                    s.push(string(1, c)); // Push opening symbol as string
                }
                else if (c == '}' || c == ')' || c == ']') {
                    if (s.empty()) return false; // No matching opening symbol
                    char top = s.top()[0];       // Get the top opening symbol
                    if ((c == '}' && top != '{') ||
                        (c == ')' && top != '(') ||
                        (c == ']' && top != '[')) { // Check if the pair matches with its opening symbol
                        return false; // Mismatched pair
                    }
                    s.pop(); // Remove the opening symbol from the stack
                }
            }
        }
    }
    return s.empty(); // If the stack is empty, all symbols matched
}

void open_input_file(ifstream& infile) {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;
    infile.open(filename);
    while(!infile) {
        cout << "The file does not exist. Please enter a valid filename: ";
        cin >> filename;
        infile.clear();
        infile.open(filename);
    }
}

int main() {
    ifstream infile;
    open_input_file(infile);

    if (isBalanced(infile)) {
        cout << "The symbols are balanced." << endl;
    } else {
        cout << "The symbols are not balanced." << endl;
    }

    infile.close();
    return 0;
}