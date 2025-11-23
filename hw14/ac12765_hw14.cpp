/*
Homework 14: Divide & Conquer
    (Weiss 7.40): The following divide-and-conquer algorithm is proposed for finding the
simultaneous maximum and minimum: If there is one item, it is the maximum and minimum, and if
there are two items, then compare them, and in one comparison you can find the maximum and
minimum. Otherwise, split the input into two halves, divided as evenly as possible (if N is odd, one
of the two halves will have one more element than the other). Recursively find the maximum and
minimum of each half, and then in two additional comparisons produce the maximum and minimum
for the entire problem.

    Write the above function which will take in a vector and solve the problem, producing a
vector of two elements, the min and max. Include a main that tests your function.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findMinMax(const vector<int>& arr, int left, int right) {
    if (left == right) {
        // Base case: only one element
        return {arr[left], arr[left]};
    } else if (right - left == 1) {
        // Base case: two elements
        return {min(arr[left], arr[right]), max(arr[left], arr[right])};
    } else {
        // Divide the array into two halves
        int mid = left + (right - left) / 2;
        vector<int> leftMinMax = findMinMax(arr, left, mid);
        vector<int> rightMinMax = findMinMax(arr, mid + 1, right);
        
        // Combine results
        int minValue = min(leftMinMax[0], rightMinMax[0]);
        int maxValue = max(leftMinMax[1], rightMinMax[1]);
        
        return {minValue, maxValue};
    }
}

int main() {
    vector<int> arr = {3, 5, 1, 8, 2, 7, 4, 6};
    
    if (arr.empty()) {
        cout << "Array is empty." << endl;
        return 0;
    }
    
    vector<int> result = findMinMax(arr, 0, arr.size() - 1);
    
    cout << "Minimum: " << result[0] << ", Maximum: " << result[1] << endl;
    
    return 0;
}