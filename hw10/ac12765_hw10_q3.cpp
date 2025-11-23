/*
Question 3:
In this question, you will write two versions of a program that reads from the user a 
sequence of positive integers ending with -1, and another positive integer num that the 
user wishes to search for.  
The program should then print all the line numbers in sequence entered by the user, that 
contain num, or a message saying that num does not show at all in the sequence. 

Your program should interact with the user exactly as it shows in the following example: 
Please enter a sequence of positive integers, each in a separate line. 
End you input by typing -1.  
13 
5 
8 
2 
9 
5 
8 
8
-1 
Please enter a number you want to search. 
5 
5 shows in lines 2, 6. 

a)  The first version of the program, is not allowed to use the vector data structure.	
b)  The second version of the program, should use the vector data structure.		

Implementation requirements (for both programs): 
1.  Think how to break down your implementation to functions. 
2.  Your programs should run in linear time. That is, if there are n numbers in the input 
    sequence, your program should run in 𝜃(𝑛). 
3.  Write the two programs in two functions named main1() and main2(). Also have 
    the main() test these two functions.
*/

#include <iostream>
#include <string>
#include <vector>
//using namespace std;

void main1();
void main2();
void doublingCapacity(int*& arr, int& capacity);

int main() {
    std::cout << "Main1:\n";
    main1();
    std::cout << "Main2:\n";
    main2();

    return 0;
}

void main1() {
    std::cout << "Please enter a sequence of positive integers, each in a separate line.\n";
    std::cout << "End your input by typing -1.\n";

    int num, searchNum;
    int capacity = 1;
    int* numArr = new int[capacity];
    int numArrSize = 0; 

    while (true) {
        std::cin >> num;
        if (num == -1) break;
        if (numArrSize == capacity) {
            doublingCapacity(numArr, capacity);
        }

        numArr[numArrSize++] = num;
    }

    std::cout << "Please enter a number you want to search.\n";
    std::cin >> searchNum;

    bool found = false;
    std::string lines;
    for (int i = 0; i < numArrSize; i++) {
        if (numArr[i] == searchNum) {
            lines += std::to_string(i + 1) + ", ";
            found = true;
        }
    }
    if (found) {
        std::cout << searchNum << " shows in lines ";
        std::cout << lines.substr(0, lines.size() - 2) << ".\n"; // Remove last comma and space
    } else {
        std::cout << searchNum << " does not show at all in the sequence.\n";
    }

    delete[] numArr;
}

void main2() {
    std::cout << "Please enter a sequence of positive integers, each in a separate line.\n";
    std::cout << "End your input by typing -1.\n";

    std::vector<int> numbers;
    int num;

    while (true) {
        std::cin >> num;
        if (num == -1) break;
        numbers.push_back(num);
    }

    std::cout << "Please enter a number you want to search.\n";
    int searchNum;
    std::cin >> searchNum;

    bool found = false;
    std::string lines;
    for (size_t i = 0; i < numbers.size(); i++) {
        if (numbers[i] == searchNum) {
            lines += std::to_string(i + 1) + ", ";
            found = true;
        }
    }
    if (found) {
        std::cout << searchNum << " shows in lines ";
        std::cout << lines.substr(0, lines.size() - 2) << ".\n"; // Remove last comma and space
    } else {
        std::cout << searchNum << " does not show at all in the sequence.\n";
    }
}

void doublingCapacity(int*& arr, int& capacity) {
    int* resizedArr = new int[capacity * 2];
    for (int i = 0; i < capacity; i++) {
        resizedArr[i] = arr[i];
    }

    delete [] arr;

    arr = resizedArr;
    capacity = 2 * capacity;
}