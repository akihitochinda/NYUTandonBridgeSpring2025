/*
Question 2:
int* findMissing(int arr[], int n, int& resArrSize) 

This function gets an array of integers arr and its logical size n. All elements in arr are 
in the range {0, 1, 2, … , n}.  
Note that since the array contains n numbers taken from a range of size n+1, there must 
be at least one number that is missing (could be more than one number missing, if there 
are duplicate values in arr).   
When called, it should create and return a new array, that contains all the numbers in 
range {0, 1, 2, … , n} that are not in arr. The function should also update the output 
parameter, resArrSize, with the logical size of the new array that was created. 

For example, if arr=[3, 1, 3, 0, 6, 4], after calling  
findMissing(arr, 6, resArrSize), the function should create and return an 
array that contains [2, 5], and update the value in resArrSize to be 2. 

Implementation requirements: 
1.  Your function should run in linear time. That is, it should run in 𝜃(𝑛). 
2.  Write a main() program that tests this function..
*/

#include <iostream>
//#include <vector>
//using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);

int main() {
    int arr[] = {3, 1, 3, 0, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int resArrSize;

    int* missingNumbers = findMissing(arr, n, resArrSize);

    std::cout << "Missing numbers: [";
    for (int i = 0; i < resArrSize; i++) {
        std::cout << missingNumbers[i];
        if (i < resArrSize - 1) {
           std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
    std::cout << "Logical size of the new array: " << resArrSize << std::endl;

    delete[] missingNumbers;
    return 0;
}

int* findMissing(int arr[], int n, int& resArrSize) {
    bool found[n + 1] = {false}; // boolean array to track found numbers
    // int found[n + 1] = {0}; // integer array to count occurrences of numbers
    for (int i = 0; i < n; i++) {
        if (0 <= arr[i] && arr[i] <= n) {
            found[arr[i]] = true; // Mark the number as found
        }
        // found[arr[i]]++; // Increment the count for the number
    }

    resArrSize = 0;
    for (int i = 0; i <= n; i++) {
        if (!found[i]) {
        // if (found[i] == 0) {
            resArrSize++;
        }
    }

    int* result = new int[resArrSize];
    int index = 0;
    for (int i = 0; i <= n; i++) {
        if (!found[i]) {
        // if (found[i] == 0) {
            result[index++] = i;
        }
    }

    return result;
}