/*
Given an array of numbers, write a function to move all 0s to the end of the array while
maintaining the relative order of the non-zero elements. Do this in-place. This should run in
Θ(n).
Example: [0,2,0,1,0] -> [2, 1, 0, 0, 0]
*/

#include <iostream>
using namespace std;

void moveZeroes(int nums[], int n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            nums[j++] = nums[i]; // Move non-zero element to the front using the common array index j
        }
    }

    for (int i = j; i < n; i++) { // Start from the last non-zero index j
        nums[i] = 0; // Fill remaining positions with zeros
    }
}

int main() {
    int nums[] = {0, 2, 0, 1, 0};
    int n = sizeof(nums) / sizeof(nums[0]);

    moveZeroes(nums, n);

    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << nums[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}