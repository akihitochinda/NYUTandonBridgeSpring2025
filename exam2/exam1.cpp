/*
Question 8
    Give a recursive C++ implementation for the function:
int countXs(int *arr, int n, int x)
    The above function is given arr, a base address of an array that will contain non-zero integers, its
logical size n, and another non-zero integer x. When this countXs function is called, it should return the
number of times x has appeared in arr.

 1. For example, if arr = {1,-5, 2,-5,-5, 9,-5, 3}, after calling countXs(arr, 10,-5), this
    function should return 4 because-5 has appeared 4 times in arr.
 2. For example, if arr = {1, 5, 20, 12, 2, 5,-5, 7}, after calling countXs(arr, 8, 3), this func-
    tion should return 0. Because 3 has appeared 0 time in arr.
 3. For example, if arr = {-1, 3, 9, 3, 2, 3,-5, 3, 2, 3,-5}, after calling countXs(arr, 11,
    3), this function should return 5 because 3 has appeared 5 times in arr.
 
Implementation requirements:
 •  Your function should run in worst case Linear time. That is, it should run in θ(n) where n = logical
    size of the array arr.
 •  Your function must be recursive.
 •  You are not allowed to use C++ syntactic features that were not covered in the Bridge program so far.
 •  Assume that zero (0) is not in the elements in arr.
 
Note: You don’t need to write a main() function.
*/

#include <iostream>
using namespace std;

int countXs(int *arr, int n, int x) {
    // Base case: if the array is empty, return 0
    if (n == 0) {
        return 0;
    }
    
    // Check the last element of the array
    int count = (arr[n - 1] == x) ? 1 : 0;
    
    // Recursive call for the rest of the array
    return count + countXs(arr, n - 1, x);
}

int main() {
    int arr1[] = {1, -5, 2, -5, -5, 9, -5, 3};
    cout << countXs(arr1, 10, -5) << endl; // Output: 4

    int arr2[] = {1, 5, 20, 12, 2, 5, -5, 7};
    cout << countXs(arr2, 8, 3) << endl; // Output: 0

    int arr3[] = {-1, 3, 9, 3, 2, 3, -5, 3, 2, 3, -5};
    cout << countXs(arr3, 11, 3) << endl; // Output: 5

    return 0;
}