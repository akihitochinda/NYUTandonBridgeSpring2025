/*
13. Implement a  MinStack . Design a stack that supports push, pop, top, and retrieving the minimum
    element in constant time.

        push(x) -- Push element x onto stack.
        pop() -- Removes the element on top of the stack.
        top() -- Get the top element.
        getMin() -- Retrieve the minimum element in the stack.
*/

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> s;
    stack<int> min;
public:
    /** initialize your data structure here. */
    MinStack() {
        return;
    }

    void push(int x) {
        // Check if the stack is empty or not, preventing access to an empty min stack
        if(s.empty() || x <= min.top()){
            min.push(x); // Push the new minimum onto the min stack
        }
        s.push(x); // Push the element onto the main stack
    }

    void pop() {
        if(s.empty()){return;}
        if(s.top() == min.top()){ // If the popped element is the current minimum
            min.pop(); // Remove the current minimum from the min stack
        }
        s.pop(); // Pop the element from the main stack
    }

    int top() {
        return s.top();
    }
    
    int getMin() {
        if(s.empty()){return -1;}
        return min.top(); // Return the current minimum element
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main() {
    MinStack obj;
    obj.push(5);
    cout << "Pushed 5, min: " << obj.getMin() << endl;
    obj.push(2);
    cout << "Pushed 2, min: " << obj.getMin() << endl;
    obj.push(8);
    cout << "Pushed 8, min: " << obj.getMin() << endl;
    obj.push(1);
    cout << "Pushed 1, min: " << obj.getMin() << endl;

    obj.pop();
    cout << "Popped top, new top: " << obj.top() << ", min: " << obj.getMin() << endl;

    obj.pop();
    cout << "Popped top, new top: " << obj.top() << ", min: " << obj.getMin() << endl;

    obj.push(0);
    cout << "Pushed 0, min: " << obj.getMin() << endl;

    obj.pop();
    cout << "Popped top, new top: " << obj.top() << ", min: " << obj.getMin() << endl;

    obj.pop();
    cout << "Popped top, new top: " << obj.top() << ", min: " << obj.getMin() << endl;

    return 0;
}