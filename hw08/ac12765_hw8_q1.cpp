/*
Question 1:
1.  Implement the function: int minInArray(int arr[], int arrSize)  
    This function is given arr, an array of integers, and its logical size, arrSize. When called, 
    it returns the minimum value in arr. 

2.  Write a program that reads from the user a sequence of 20 integers (unnecessarily different 
    from one another) into an array, and outputs the minimum value, and all the indices it 
    appears in the array.  

    Your program should interact with the user exactly as it shows in the following example: 
    Please enter 20 integers separated by a space:		
    14 5 12 5 6 14 5 12 14 12 14 6 8 7 5 136 9 2189 10 6	
    The	minimum	value is 5, and	it is located in the following indices: 1 3 6 14 

    Note: You may want to define additional functions for your program to use.
*/

#include <iostream>
//using namespace std;

int minInArray(int arr[], int arrSize);

int main() {
    const int arrSize = 20;
    int arr[arrSize];
    
    std::cout << "Please enter 20 integers separated by a space: ";
    for (int i = 0; i < arrSize; i++) {
        std::cin >> arr[i];
        if (std::cin.fail()) {
            std::cerr << "Invalid input. Please enter integers only." << std::endl;
            return 1;
        }
    }

    int minValue = minInArray(arr, arrSize);
    std::cout << "The minimum value is " << minValue << ", and it is located in the following indices: ";

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == minValue) {
            std::cout << i << " ";
        }
    }
    
    std::cout << std::endl;
    return 0;
}

int minInArray(int arr[], int arrSize) {
    int minValue = arr[0];

    for (int i = 1; i < arrSize; i++) {
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
    }

    return minValue;
}