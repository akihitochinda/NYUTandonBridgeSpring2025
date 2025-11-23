/*
Question 3:
Write two recursive versions of the function minInArray. The function will be given a
sequence of elements and should return the minimum value in that sequence. The two versions
differ from one another in the technique we use to pass the sequence to the function.

In version 1 – The prototype of the function should be:
int minInArray1(int arr[], int arrSize)
Here, the function is given arr, an array of integers, and its logical size, arrSize.
The function should find the minimum value out of all the elements in positions:
0, 1, 2, ..., arrSize-1.

In version 2 – The prototype of the function should be:
int minInArray2(int arr[], int low, int high)
Here, the function is given arr, an array of integers, and two additional indices: low and high
(low ≦ high), which indicate the range of indices that need to be considered.
The function should find the minimum value out of all the elements in positions:
low, low+1, ..., high.

Use the following main to check your program:
int main() {
    int arr[10] = {9, -2, 14, 12, 3, 6, 2, 1, -9, 15};
    int res1, res2, res3, res4;
    
    res1 = minInArray1(arr, 10);
    res2 = minInArray2(arr, 0, 9);
    cout<<res1<<” “<<res2<<endl; //should both be -9
    
    res3 = minInArray2(arr, 2, 5);
    res4 = minInArray1(arr+2, 4); //arr+2 is equivalent to &(arr[2])
    cout<<res3<<” “<<res4<<endl; //should both be 3
    
    return 0;
}
*/

#include <iostream>
//using namespace std;

int minInArray1(int arr[], int arrSize);
int minInArray2(int arr[], int low, int high);

int main() {
    int arr[10] = {9, -2, 14, 12, 3, 6, 2, 1, -9, 15};
    int res1, res2, res3, res4;
    
    res1 = minInArray1(arr, 10);
    res2 = minInArray2(arr, 0, 9);
    std::cout << res1 << " " << res2 << std::endl; // should both be -9
    
    res3 = minInArray2(arr, 2, 5);
    res4 = minInArray1(arr+2, 4); // arr+2 is equivalent to &(arr[2])
    std::cout << res3 << " " << res4 << std::endl; // should both be 3
    
    return 0;
}

int minInArray1(int arr[], int arrSize) {
    if (arrSize == 1) { // Base case: if there's only one element, return it
        return arr[0];
    } else {
        int min;
        min = minInArray1(arr, arrSize - 1); // Recursive call reducing the size of the array: arrSize - 1 = logical size of the array
        return (arr[arrSize - 1] < min) ? arr[arrSize - 1] : min; // arr[arrSize - 1] receives a pointer to the third element (&(arr[2])) in res4 case, then the "start" of the array is now arr[2] with a new "subarray", reducing the size to 4
    }
}

int minInArray2(int arr[], int low, int high) {
    if (low == high) { // Base case: if low equals high, return the single element
        return arr[low];
    } else {
        int min;
        min = minInArray2(arr, low, high - 1); // Recursive call reducing the range: arrSize high - 1 = highest index of the array
        return (arr[high] < min) ? arr[high] : min;
    }
}