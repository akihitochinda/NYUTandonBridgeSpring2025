/*
10. Given the struct, implement the following functions.
*/

#include <iostream>
#include <algorithm>

struct ListNode {
    int val; // Value of the node
    ListNode* next; // Pointer to the next node
    ListNode(int val):val(val),next(nullptr){} // Constructor: initializes value and next pointer
};

ListNode* reverse_linked_list(ListNode* head){
    // Reverse the linked list and return the new head after reversing
    ListNode* prev = nullptr; // Previous node
    ListNode* cur = head; // Current node

    while (cur != nullptr) { // Traverse until the end of the list
        ListNode* next = cur->next; // Save the next node, so you don’t lose the rest of the list after changing the link.
        cur->next = prev; // Reverse the link: point the current node’s next to the previous node (instead of the next node).
        prev = cur; // Move prev forward to the current node (it will be the previous node in the next iteration).
        cur = next; // Move cur forward to the next node (continue traversing the list).
    }

    return prev; // New head of the reversed list
}

/*
Example:
Suppose your list is: 1 -> 3 -> 5 -> 7 -> nullptr

First iteration:
cur = 1, next = 3
1->next = nullptr (was pointing to 3, now points to nothing)
prev = 1, cur = 3
Second iteration:
cur = 3, next = 5
3->next = 1
prev = 3, cur = 5
Third iteration:
cur = 5, next = 7
5->next = 3
prev = 5, cur = 7
Fourth iteration:
cur = 7, next = nullptr
7->next = 5
prev = 7, cur = nullptr
Now, prev points to 7, and the list is: 7 -> 5 -> 3 -> 1 -> nullptr
*/

bool is_target_in_list(ListNode* head, int target){
    // check if the linked list contains the target
    while (head != nullptr) { // Traverse the list
        if (head->val == target) { // Check if current node's value matches target
        return true;
        }
        head = head->next; // Move to the next node
    }

    return false;
}

int find_max(ListNode* head){
    // find the largest value in the node
    int max = head->val;
    
    while (head != nullptr) { // Traverse the list
        max = std::max(max, head->val); // Update max if current node's value is larger
        head = head->next; // Move to the next node
    }

    return max;
}

int main() {
    // Create a linked list: 1 -> 3 -> 5 -> 7 -> nullptr
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(5);
    head->next->next->next = new ListNode(7);

    // Test find_max
    std::cout << "Max value: " << find_max(head) << std::endl; // Should print 7

    // Test is_target_in_list
    std::cout << "Is 5 in list? " << (is_target_in_list(head, 5) ? "Yes" : "No") << std::endl; // Yes
    std::cout << "Is 10 in list? " << (is_target_in_list(head, 10) ? "Yes" : "No") << std::endl; // No

    // Test reverse_linked_list
    ListNode* reversed = reverse_linked_list(head);
    std::cout << "Reversed list: ";
    ListNode* cur = reversed;
    while (cur) {
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << std::endl;

    // Free memory
    cur = reversed;
    while (cur) {
        ListNode* next = cur->next;
        delete cur;
        cur = next;
    }

    return 0;
}