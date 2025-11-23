/*
12. Implement a Stack class using queues.
*/

#include <queue>
#include <iostream>

using namespace std;

// A stack is LIFO (Last-In, First-Out): the last element pushed should be the first one accessed.
// A queue is FIFO (First-In, First-Out): the first element pushed is the first one accessed.
// To implement a stack using queues, we must access the "last" element in the queue, which is only possible by moving all earlier elements out of the way.

class Stack
{
    queue<int> q1, q2;
    int curr_size;

public:
    Stack()
    {
        curr_size = 0;
    }

    // In pop():
    // You want to remove the top (last pushed) element.
    // To do this, you move all but the last element from q1 to q2, then remove the last element from q1.
    // After that, you swap q1 and q2 so q1 is ready for the next operation.
    void pop() // Remove the top element from the stack
    {
        if (q1.empty())
            return;
        
        // Leave one element in q1 and
        // push others in q2.
        while (q1.size() != 1)
        {
            q2.push(q1.front()); // Push front element of q1 to q2
            q1.pop(); // Pop front element from q1
        }
        
        // Pop the only left element
        // from q1
        q1.pop(); // Pop the last element from q1
        curr_size--; // Decrease the current size

        // swap the names of two queues
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    void push(int x) // Push element onto the stack
    {
        q1.push(x); // Push element onto q1
        curr_size++; // Increase the current size
    }

    // In top():
    // You want to peek at the top (last pushed) element without removing it.
    // So you move all but the last element from q1 to q2, get the last element (which is the top of the stack), then push it to q2 (so it stays in the stack).
    // Finally, you swap q1 and q2 so the order is preserved for future operations.
    int top() // Get the top element of the stack
    {
        if (q1.empty())
            return -1;

        while( q1.size() != 1 )
        {
            q2.push(q1.front()); // Push front element of q1 to q2
            q1.pop(); // Pop front element from q1
        }
            
        // last pushed element
        int temp = q1.front();

        // to empty the auxiliary queue after
        // last operation
        q1.pop();

        // push last element to q2
        q2.push(temp);
        
        // swap the two queues names
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
        return temp;
    }

    int size() // Get the current size of the stack
    {
        return curr_size; // Return the current size
    }
};

// Driver code
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    
    cout << "current size: " << s.size()
        << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << "current size: " << s.size()
        << endl;
    return 0;
}