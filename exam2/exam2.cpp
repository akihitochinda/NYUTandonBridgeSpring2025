/*
Question 9
    Give a recursive C++ implementation for the function:
void combineSortedArrays(int S1[], int S2[], int n1, int n2, vector<int> &CombinedArray);
    The above function is given two sorted arrays S1 and S2 that will contain integers in non-decreasing
order, an integer n1 that will indicate the logical size of the array S1, an integer n2 that will indicate
the logical size of the array S2, and an address to an integer vector CombinedArray (type vector<int>)
that will contain the merged integers sorted in non-decreasing order. When this combineSortedArrays
function is called, it should merge the elements of S1 and S2 in sorted order in CombinedArray vector (type
vector<int>) and remove duplicates. Note that S1 will contain unique integers sorted in non-decreasing
order and S2 will contain unique integers sorted in non-decreasing order, but same elements may appear
in both S1 and S2. After merging, all the elements in CombinedArray vector (type vector<int>) should be
unique (there will be no duplicate elements) and will be sorted in non-decreasing order.

 1. For example, if S1 = {-100,-75,-20, 15, 20}, S2 = {-75,-20,-10, 20} and type of
    CombinedArray variable is vector<int>, after calling combineSortedArrays(S1, S2, 4, 4,
    CombinedArray), CombinedArray should be {-100,-75,-20,-10, 15, 20}.
 2. For example, if S1 = {-1, 5, 15, 17, 26, 44}, S2 = {-10, 5, 24, 30, 50} and type of
    CombinedArray variable is vector<int>, after calling combineSortedArrays(S1, S2, 6, 5,
    CombinedArray), CombinedArray should be {-10,-1, 5, 15, 17, 24, 26, 30, 44, 50}.
 3. For example, if S1 = {-10, 5, 15}, S2 = {0, 15, 24, 30, 90} and type of CombinedArray
    variable is vector<int>, after calling combineSortedArrays(S1, S2, 3, 5, CombinedArray),
    CombinedArray should be {-10, 0, 5, 15, 24, 30, 90}.
 
Implementation requirements:
 •  Your function should run in θ(n1 + n2) where n1 = logical size of the array S1 and n2 = logical size of
    the array S2. For simplicity, you can assume that amortized θ(1) is the same as θ(1).
 •  You are not allowed to use C++ syntactic features that were not covered in the Bridge program so far.
 •  You can assume that initial value of CombinedArray variable (type vector<int>) is Empty.
 
Note: You don’t need to write a main() function.
*/

#include <iostream>
#include <vector>
using namespace std;

void combineSortedArrays(int S1[], int S2[], int n1, int n2, vector<int> &CombinedArray) {
    // Base case: if both arrays are empty, return
    if (n1 == 0 && n2 == 0) {
        return;
    }

    // If S1 is empty, add elements from S2
    if (n1 == 0) {
        for (int i = 0; i < n2; ++i) {
           if (CombinedArray.empty() || CombinedArray.back() != S2[i]) { // Check if the result vector is empty and the last element is not equal to S2[i] to prevent duplicates
              CombinedArray.push_back(S2[i]);
           }
        }
        return;
    }

    // If S2 is empty, add elements from S1
    if (n2 == 0) {
        for (int i = 0; i < n1; ++i) {
            if (CombinedArray.empty() || CombinedArray.back() != S1[i]) { // Check if the result vector is empty and the last element is not equal to S1[i] to prevent duplicates
                CombinedArray.push_back(S1[i]);
            }
        }
        return;
    }

    // Recursive case: compare the first elements of both arrays
    if (S1[0] < S2[0]) {
        if (CombinedArray.empty() || CombinedArray.back() != S1[0]) { // Check if the result vector is empty and the last element is not equal to S1[0] to prevent duplicates
            CombinedArray.push_back(S1[0]);
        }
        combineSortedArrays(S1 + 1, S2, n1 - 1, n2, CombinedArray); // This moves the S1 pointer forward by one and reduces its size by one
    } else if (S1[0] > S2[0]) {
        if (CombinedArray.empty() || CombinedArray.back() != S2[0]) {
            CombinedArray.push_back(S2[0]);
        }
        combineSortedArrays(S1, S2 + 1, n1, n2 - 1, CombinedArray); // This moves the S2 pointer forward by one and reduces its size by one
    } else { // S1[0] == S2[0]
        if (CombinedArray.empty() || CombinedArray.back() != S1[0]) {
            CombinedArray.push_back(S1[0]);
        }
        combineSortedArrays(S1 + 1, S2 + 1, n1 - 1, n2 - 1, CombinedArray); // This moves both array pointers forward by one (skipping the duplicate in both arrays) and reduces their sizes by one
    }
}

int main() {
    int S1[] = {-100, -75, -20, 15, 20};
    int S2[] = {-75, -20, -10, 20};
    vector<int> CombinedArray;

    combineSortedArrays(S1, S2, 5, 4, CombinedArray);

    cout << "[";
    for (int num : CombinedArray) {
        cout << num;
        if (num != CombinedArray.back()) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}