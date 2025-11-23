/*
Given an array of nums, find the length of the longest sequence of zeroes recursively. You can
use the std::max function.
Example: maxZeroLength([0,0,1,0,0,0], 6, 0) = 3
*/

#include <iostream>
using namespace std;

int maxZeroLength(int nums[], int len, int startIdx){
    //base case -->
    if(startIdx == len){ // If startIdx has reached the length of the array, return 0
        return 0;
    }
    int maxLen = 0;
    while (startIdx < len && nums[startIdx++] == 0){ // Increment startIdx while it points to zero
        maxLen++; // Count the length of the current sequence of zeroes
    }
    return max(maxLen, maxZeroLength(nums, len, startIdx)); // Recursive call to find the maximum length of zeroes in the rest of the array
}

int main() {
    int nums[] = {0, 0, 1, 0, 0, 0};
    int len = sizeof(nums) / sizeof(nums[0]);
    cout << maxZeroLength(nums, len, 0) << endl;
    return 0;
}