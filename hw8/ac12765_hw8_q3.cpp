/*
Question 3:
Implement following	functions:		
a.  void reverseArray(int arr[], int arrSize)	
    That takes arr, an array of integers, and its size, arrSize. When called, it reorders the 
    elements of the array to appear in a reverse order. 
    For example, if arr is an array containing [1, 2, 3, 4], after calling reverseArray, arr 
    will look like: [4, 3, 2, 1]. 

b.  void removeOdd(int arr[], int& arrSize)	
    That takes arr, an array of integers, and its size, arrSize. When called, the function 
    alters arr so that the only numbers in it at the end are the even ones, which should remain 
    in their original relative order.  
    Additionally, the function updates arrSize so it contains the new logical size of the array 
    after removing the odd numbers (note that arrSize is a parameter used both for input 
    and output).  
    For example, if arr is an array containing [1, 2, 3, 4], after calling removeOdd, arr will 
    look like: [2, 4], and the parameter arrSize will update to 2. Notice the values in arr[2] 
    and arr[3] are discarded. 

c.  void splitParity(int arr[], int arrSize) 
    That takes arr, an array of integers, and its size, arrSize. When called, the function	
    changes the order of numbers in arr so that all the odd numbers will appear first, and all 
    the even numbers will appear last. Note that the inner order of the odd numbers and the 
    inner order of the even numbers don’t matter. 
    For example, if arr is an array containing [1, 2, 3, 4], after calling splitParity, arr 
    could look like: [3, 1, 2, 4].

Implementation requirements: 
1.  In all three functions, you are not allowed to use an auxiliary array (a temporary local array).  
2.  Pay attention to the running time of your functions. For each one of the functions above, an 
    efficient implementation would run in a linear time (that is Θ(𝑎𝑟𝑟𝑆𝑖𝑧𝑒)). 
Note: You don’t have to submit a main function for this question. You may use the following 
program to test your functions: 
#include <iostream> 
using namespace std; 

void printArray(int arr[], int arrSize); 

int main() { 
    int arr1[10] = {9, 2, 14, 12, -3}; 
    int arr1Size = 5; 

    int arr2[10] = {21, 12, 6, 7, 14}; 
    int arr2Size = 5; 

    int arr3[10] = {3, 6, 4, 1, 12}; 
    int arr3Size = 5; 
    
    reverseArray(arr1, arr1Size); 
    printArray(arr1, arr1Size); 
    
    removeOdd(arr2, arr2Size); 
    printArray(arr2, arr2Size); 
    
    splitParity(arr3, arr3Size); 
    printArray(arr3, arr3Size); 
    
    return 0; 
} 

void printArray(int arr[], int arrSize){ 
    int i; 

    for (i = 0; i < arrSize; i++) { 
        cout<<arr[i]<<' '; 
    } 
    cout<<endl; 
} 

When running this program you should expect the following output (the output for 
splitParity could be different):
-3 12 14 2 9 
12 6 14 
1 3 6 4 12 
*/

#include <iostream>
using namespace std;

void printArray(int arr[], int arrSize); 
void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);

int main() {
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;

    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;

    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;

    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);

    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);

    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);

    return 0;
}

void printArray(int arr[], int arrSize){ 
    int i; 

    for (i = 0; i < arrSize; i++) { 
        cout<<arr[i]<<' '; 
    } 
    cout<<endl; 
} 

void reverseArray(int arr[], int arrSize) {
    for(int i = 0; i < arrSize / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[arrSize - 1 - i];
        arr[arrSize - 1 - i] = temp;
    }
}

void removeOdd(int arr[], int& arrSize) {
    int NewEvenIndex = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 == 0) {
            arr[NewEvenIndex++] = arr[i]; // store even numbers in order, pushing them to the front
        }
    }
    arrSize = NewEvenIndex; // update the arrsize to the number of even elements so that the rest of the array is ignored
}

void splitParity(int arr[], int arrSize) {
    int NewOddIndex = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 != 0) {
            if (NewOddIndex != i) { // not necessary to swap if the current index is already odd
                int temp = arr[NewOddIndex];
                arr[NewOddIndex] = arr[i];
                arr[i] = temp;
            }
            NewOddIndex++;
        }
    }
}