/*
Question 7
    Given an STL stack, provide a templated function which will determine the maximum value in the stack
(the elements can be compared using operator<). Your function must take a stack by reference and the
values on the stack must be the same at the beginning and the end.
*/

#include <iostream>
#include <stack>
#include <algorithm> // for std::max

//using namespace std;

template <typename T>
T findMaxInStack(std::stack<T>& s) {
    if (s.empty()) {
        throw std::runtime_error("Stack is empty");
    }

    std::stack<T> tempStack;
    T maxValue = s.top();

    // Transfer elements to tempStack and find max
    while (!s.empty()) {
        T current = s.top();
        s.pop(); // To access elements deeper in the stack, which is a Last-In-First-Out (LIFO) container.
        maxValue = std::max(maxValue, current);
        tempStack.push(current);
    }

    // Restore original stack
    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }

    return maxValue;
}

int main() {
    std::stack<int> s;
    s.push(1);
    s.push(9);
    s.push(3);
    s.push(5);
    // Original stack: [1, 9, 3, 5] (Top is 5)
    // tempStack: [5, 3, 9, 1] (Top is 1)
    // Restored stack: [1, 9, 3, 5] (Top is 5 again)

    try {
        int maxValue = findMaxInStack(s);
        std::cout << "Max value in stack: " << maxValue << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}