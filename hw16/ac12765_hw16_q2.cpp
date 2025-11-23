/*
Homework 16: Stacks & Queues
    Part 2. Although a queue is "best" implemented with a list, it can be implemented with a
vector if you take into account the starting position of the queue. For example, if five elements
are pushed onto the queue, the start of the queue is at position zero and the end is at position 4.
If we, then, pop two elements, the start would be at position 2 and the end at position 4. The
two "popped" elements are not really removed from the vector, and that avoids the O(N) time
problem for the pop function.

    Implement a class which uses a vector to store the queue. Be mindful of performance,
such that if the queue is empty, the size of the underlying vector is "reset." You do not need to
submit a main function for this, just the class is fine.
*/

#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Queue {
private:
    vector<T> data; // Vector to store queue elements
    int start;      // Start index of the queue
    int end;        // End index of the queue
public:
    Queue() : start(0), end(0) {}

    // Push an element onto the queue
    void push(const T& value) {
        if (end == data.size()) {
            data.push_back(value);
        } else {
            data[end] = value;
        }
        end++;
    }

    // Pop an element from the front of the queue
    void pop() {
        if (start < end) {
            start++;
        }
        // Reset the vector if the queue is empty
        if (start == end) {
            data.clear();
            start = 0;
            end = 0;
        }
    }

    // Get the front element of the queue
    T front() const {
        if (start < end) {
            return data[start];
        }
        throw out_of_range("Queue is empty");
    }

    // Get the back element of the queue
    T back() const {
        if (start < end) {
            return data[end - 1];
        }
        throw out_of_range("Queue is empty");
    }

    // Check if the queue is empty
    bool empty() const {
        return start == end;
    }


    // Get the size of the queue
    int size() const {
        return end - start;
    }
};

int main() {
    Queue<int> q;

    for (int i = 0; i < 10; i++) {
        q.push(i);
    }

    cout << "Front: " << q.front() << endl; // Should print 0
    cout << "Back: " << q.back() << endl;   // Should print 9
    cout << "Size: " << q.size() << endl;   // Should print 10

    for (int i = 0; i < 5; i++) {
        q.pop();
    }

    cout << "Front: " << q.front() << endl; // Should print 5
    cout << "Back: " << q.back() << endl;   // Should print 9
    cout << "Size: " << q.size() << endl;   // Should print 5

    return 0;
}