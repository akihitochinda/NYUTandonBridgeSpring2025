/*
Question 3:
In this question, you will write four versions of a function getPosNums that gets an
array of integers arr, and its logical size. When called it creates a new array containing
only the positive numbers from arr.
For example, if arr=[3, -1, -3, 0, 6, 4], the functions should create an array
containing the following 3 elements: [3, 6, 4],

The four versions you should implement differ in the way the output is returned.
The prototypes of the functions are:
a)  int* getPosNums1(int* arr, int arrSize, int& outPosArrSize)
    returns the base address of the array (containing the positive numbers), and updates
    the output parameter outPosArrSize with the array’s logical size.

b)  int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr)
    returns the base address of the array (containing the positive numbers), and uses
    the pointer outPosArrSizePtr to update the array’s logical size.

c)  void getPosNums3(int* arr, int arrSize,
                     int*& outPosArr, int& outPosArrSize)
    updates the output parameter outPosArr with the base address of the array
    (containing the positive numbers), and the output parameter outPosArrSize with
    the array’s logical size.

d)  void getPosNums4(int* arr, int arrSize,
                     int** outPosArrPtr, int* outPosArrSizePtr)
    uses the pointer outPosArrPtr to update the base address of the array (containing
    the positive numbers), and the pointer outPosArrSizePtr to update the array’s
    logical size.

Notes: You should also write a main program that calls and tests all these functions.
*/

#include <iostream>
//using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);

int main() {
    int arr[] = {3, -1, -3, 0, 6, 4};
    int arrSize = sizeof(arr) / sizeof(arr[0]); // for determining the number of elements in a statically allocated array

    // getPosNums1
    int outPosArrSize1;
    int *posArr1 = getPosNums1(arr, arrSize, outPosArrSize1);
    std::cout << "getPosNums1: ";
    for (int i = 0; i < outPosArrSize1; i++) {
        std::cout << posArr1[i] << " ";
    }
    std::cout << "\n";
    delete[] posArr1;

    // getPosNums2
    int outPosArrSize2;
    int *posArr2 = getPosNums2(arr, arrSize, &outPosArrSize2);
    std::cout << "getPosNums2: ";
    for (int i = 0; i < outPosArrSize2; i++) {
        std::cout << posArr2[i] << " ";
    }
    std::cout << "\n";
    delete[] posArr2;

    // getPosNums3
    int *posArr3;
    int outPosArrSize3;
    getPosNums3(arr, arrSize, posArr3, outPosArrSize3);
    std::cout << "getPosNums3: ";
    for (int i = 0; i < outPosArrSize3; i++) {
        std::cout << posArr3[i] << " ";
    }
    std::cout << "\n";
    delete[] posArr3;

    // getPosNums4
    int *posArr4;
    int outPosArrSize4;
    getPosNums4(arr, arrSize, &posArr4, &outPosArrSize4);
    std::cout << "getPosNums4: ";
    for (int i = 0; i < outPosArrSize4; i++) {
        std::cout << posArr4[i] << " ";
    }
    std::cout << "\n";
    delete[] posArr4;

    return 0;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
    outPosArrSize = 0;
    for (int i = 0; i < arrSize; i++) {
        if (*(arr + i) > 0) { // using pointer arithmetic to access elements / arr[i] is equivalent to *(arr + i) / arr + i is the address of the i-th element
            outPosArrSize++;
        }
    }

    int *posArr = new int[outPosArrSize]; // dynamically allocate memory for the positive numbers array
    int index = 0;
    for (int i = 0; i < arrSize; i++) {
        if (*(arr + i) > 0) {
            *(posArr + index++) = *(arr + i); // returns the base address of the array and updates the output parameter outPosArrSize with the array’s logical size / index++ is incremented after storing the value
            // posArr[index++] = arr[i]; // equivalent to *(posArr + index++) = *(arr + i);
        }
    }
    return posArr;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {
    *outPosArrSizePtr = 0;
    for (int i = 0; i < arrSize; i++) {
        if (*(arr + i) > 0) {
            (*outPosArrSizePtr)++; // using pointer dereferencing to update the value pointed by outPosArrSizePtr
        }
    }

    int *posArr = new int[*outPosArrSizePtr];
    int index = 0;
    for (int i = 0; i < arrSize; i++) {
        if (*(arr + i) > 0) {
            *(posArr + index++) = *(arr + i);
        }
    }
    return posArr;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
    outPosArrSize = 0;
    for (int i = 0; i < arrSize; i++) {
        if (*(arr + i) > 0) {
            outPosArrSize++;
        }
    }

    outPosArr = new int[outPosArrSize];
    int index = 0;
    for (int i = 0; i < arrSize; i++) {
        if (*(arr + i) > 0) {
            *(outPosArr + index++) = *(arr + i); // updates the output parameter outPosArr with the base address of the array and the output parameter outPosArrSize with the array’s logical size.
        }
    }
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
    *outPosArrSizePtr = 0;
    for (int i = 0; i < arrSize; i++) {
        if (*(arr + i) > 0) {
            (*outPosArrSizePtr)++;
        }
    }

    *outPosArrPtr = new int[*outPosArrSizePtr];
    int index = 0;
    for (int i = 0; i < arrSize; i++) {
        if (*(arr + i) > 0) {
            (*outPosArrPtr)[index++] = *(arr + i); // updates the pointer outPosArrPtr to point to the base address of the array and the pointer outPosArrSizePtr to update the array’s logical size.
            // *(outPosArrPtr + index++) or outPosArrPtr[index++] is equivalent to (*outPosArrPtr)[index++] when outPosArrPtr is dereferenced.
        }
    }
}