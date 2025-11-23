/*
Question 4:
Implement the function:
void oddsKeepEvensFlip(int arr[], int arrSize)

This function gets an array of integers arr and its logical size arrSize.
When called, it should reorder the elements of arr so that:
1.  All the odd numbers come before all the even numbers
2.  The odd numbers will keep their original relative order
3.  The even numbers will be placed in a reversed order (relative to their original order).

For example, if arr = [5, 2, 11, 7, 6, 4],
after calling oddsKeepEvensFlip(arr, 6), arr will be:
[5, 11, 7, 4, 6, 2]

Implementation requirements:
1.  Your function should run in linear time. That is, if there are n items in arr, calling
    oddsKeepEvensFlip(arr, n) will run in 𝜃(𝑛).
2.  Write a main() program that tests this function..
*/

#include <iostream>
//using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);

int main() {
    int arr[] = {5, 2, 11, 7, 6, 4};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    oddsKeepEvensFlip(arr, arrSize);

    std::cout << "Reordered array: ";
    for (int i = 0; i < arrSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

void oddsKeepEvensFlip(int arr[], int arrSize) {
    int *reorderedArr = new int[arrSize]; // for determining the number of elements in a statically allocated array
    int index = 0;
    int lastIndex = arrSize - 1;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 == 1) {
            *(reorderedArr + index++) = *(arr + i); // add odd numbers to the front in original order
            // reorderedArr[index++] = arr[i]; // equivalent to *(reorderedArr + index++) = *(arr + i);
        } else {
            *(reorderedArr + lastIndex--) = *(arr + i); // add even numbers to the back in reverse order
        }
    }

    for (int i = 0; i < arrSize; i++) {
        arr[i] = reorderedArr[i]; // copy the reordered array back to the original array
    }

    delete[] reorderedArr;
}