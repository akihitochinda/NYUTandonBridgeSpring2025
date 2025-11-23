/*
Question 2:
Give a recursive implement to the following functions:
a.  int sumOfSquares(int arr[], int arrSize)
    This function is given arr, an array of integers, and its logical size, arrSize. When called,
    it returns the sum of the squares of each of the values in arr.
    For example, if arr is an array containing [2, -1, 3, 10], calling sumOfSquares(arr, 4) will return 114 (since, 2^2 + (-1)^2 + 3^2 + 10^2 = 114).

b.  bool isSorted(int arr[], int arrSize)
    This function is given arr, an array of integers, and its logical size, arrSize. When called,
    it should return true if the elements in arr are sorted in an ascending order, or false if
    they are not.
*/

#include <iostream>
//using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main () {
    int arr1[] = {2, -1, 3, 10};
    int arrSize1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "Sum of squares: " << sumOfSquares(arr1, arrSize1) << std::endl;

    int arr2[] = {5, 2, 3, 4, 5};
    int arrSize2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "Is sorted: " << (isSorted(arr2, arrSize2) ? "true" : "false") << std::endl;

    int arr3[] = {5, 3, 4, 2, 1};
    int arrSize3 = sizeof(arr3) / sizeof(arr3[0]);
    std::cout << "Is sorted: " << (isSorted(arr3, arrSize3) ? "true" : "false") << std::endl;

    return 0;
}

int sumOfSquares(int arr[], int arrSize) {
    if (arrSize == 0) {
        return 0; // Base case: if the array size is 0, return 0
    } else {
        int temp;
        temp = arr[arrSize - 1] * arr[arrSize - 1]; // Square the last element
        return temp + sumOfSquares(arr, arrSize - 1); // Recursive call
    }
}

bool isSorted(int arr[], int arrSize) {
    if (arrSize == 0 || arrSize == 1) {
        return true; // Base case: an array of size 0 or 1 is sorted
    } else {
        return (arr[arrSize - 2] <= arr[arrSize - 1]) && isSorted(arr, arrSize - 1); // Recursive call / If the last two elements are in order, then isSorted is called on the rest of the array
    }
}