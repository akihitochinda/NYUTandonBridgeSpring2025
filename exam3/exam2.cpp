/*
Question 10
    A file on the hard drive (”input.txt” it exists, you do not need to test for it) contains integers, 
one per line.
We would like to find out how many duplicates exist in this file. Provide a function which will accept the input
file stream and will return the number of unique elements in the file.
    For example, the result would be 5 (17, 21, 3, 47, and 52 are unique), if the file contained the
following:

17
17
21
3
47
47
47
52
*/

#include <iostream>
#include <fstream>
#include <unordered_set> // For std::unordered_set

// The unordered_set is a hash-based container from the C++ Standard
// Library that automatically ensures all its elements are unique — 
// if you try to insert a duplicate, it is ignored.
int countUniqueElements(std::ifstream& inputFile) {
    std::unordered_set<int> uniqueElements;
    int number;

    while (inputFile >> number) {
        uniqueElements.insert(number);
    }

    return uniqueElements.size();
}

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    int uniqueCount = countUniqueElements(inputFile);
    std::cout << "Number of unique elements: " << uniqueCount << std::endl;

    inputFile.close();
    return 0;
}