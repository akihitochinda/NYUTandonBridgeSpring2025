/*
Homework 15: Linked Lists & File Reading
    Imagine a group of friends went out to dinner together. When the bill comes they all give
different amounts to contribute to the total, but after wish to balance everything out equally so
that each person pays the same amount. Knowing how much each person is supposed to pay is
simple enough, just add up all the amounts paid and divide by the number of people; but that
doesn’t tell anyone how to go about distributing the payments, who should give what amount to
whom?

    Write a program that will print out a step by step list of instructions of how to reimburse
everyone given the name of the person and amount of money they paid. This program should
prompt the user to enter a file name associated with the info, which will then be read in. All
information from the external file should be read into a linked list. An example is provided below:

Input:
76.8 Jason J. Jones
89 Natalie Johnson
11 Dalton Smith
44.2 Sheryl Carter
0 John Martin

Output:
Enter the filename: data.txt
Sheryl Carter, you don't need to do anything
Dalton Smith, you give Jason J. Jones $32.600000
Dalton Smith, you give Natalie Johnson $0.600000
John Martin, you give Natalie Johnson $44.200000
In the end, you should all have spent around $44.20
Process finished with exit code 0

A few things to note:
 -  Amounts and names are separated by a space (“ “), not tab.
 -  You should design your own linked list and node classes for this. The node classes
    would essentially be representing people, and you can choose whatever attributes you
    like for it, but might be helpful to store name and amount paid (from the input file), as
    well amount owed, which can be initialized to 0 and then altered later upon calculating
    the balances
 -  You must be able to read in full names, accounting for both 2 and 3 part names
 -  The information should be read into a linked list, but after that you can handle it in
    whatever format you find convenient
 -  Don’t worry about rounding to two decimal places for $ amounts
 -  You can assume the data file will have at least 2 entries with both names and amounts
    on it; we will not try to break it upon testing with empty files or bad formatting
 -  The program should not alter anything in the input file, you simply are reading it in

    If you are confused about how to calculate who pays whom what amount, a good way to
start is to calculate the target value for everyone (total sum of what everyone paid / # of people),
and see who owes money, and who is owed money (whether their “paid” attribute is above or
below the target value).
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <iomanip>
using namespace std;

// Node represents a person in the dinner group
// Each Node represents a person and is linked to the next person
class Node {
    string name;      // Person's name
    double paid;      // Amount this person paid
    double balance;   // How much they owe (+) or are owed (-) after balancing
    Node* next;       // Pointer to next node in the list
public:
    Node(string name = string(), double paid = 0, double balance = 0, Node* next = nullptr)
        : name(name), paid(paid), balance(balance), next(next) {}

    friend class LList;
};

// LList manages the singly linked list of people
// The LList class manages the head pointer and provides all list operations
class LList {
    Node* head; // Pointer to the first node in the list
public:
    LList(Node* head = nullptr) : head(head) {}

    // Big 3: destructor, copy constructor, assignment operator
    // Memory management is handled with destructor, copy constructor, and assignment operator
    ~LList(); // destructor
    LList(const LList& rhs); // copy constructor
    LList& operator=(LList rhs); // assignment operator

    // Helper functions for memory management
    void clear();
    Node* copy_linked_list(const Node* head);

    // Linked list operations
    // Adding, removing, and traversing nodes is done with pointers.
    void push_front(Node* new_node);   // Add node at front
    void pop_front();                  // Remove node at front
    void push_back(Node* new_node);    // Add node at end
    void remove(Node* node);           // Remove a specific node

    // Getters and setters
    Node* get_head() { return head; }
    int get_count();                   // Number of nodes in list
    double get_total();                // Total amount paid by all
    double get_average();              // Average amount each should pay
    void update_balances();            // Update each node's balance
    void print_transactions(ostream& outs); // Print who owes whom
    void find_receiver(ostream& outs, Node* payer); // Find who a payer should pay
};

// Destructor: delete all nodes to free memory
LList::~LList() {
    clear();
}

// Copy constructor: deep copy of the linked list
LList::LList(const LList& rhs) { 
    head = copy_linked_list(rhs.head);
}

// Assignment operator: copy-and-swap idiom for safety
LList& LList::operator=(LList rhs) {
    swap(this->head, rhs.head);
    return *this;
}

// Delete all nodes in the list
void LList::clear() {
    while(head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Recursively copy a linked list (used in copy constructor)
Node* LList::copy_linked_list(const Node* head) {
    if (!head) {
        return nullptr;
    } else {
        return new Node(head->name, head->paid, head->balance, copy_linked_list(head->next));
    }
}

// Add a node to the front of the list
void LList::push_front(Node* new_node) {
   new_node->next = head;
   head = new_node; 
}

// Remove the first node from the list
void LList::pop_front() {
    remove(head);
}

// Add a node to the end of the list
void LList::push_back(Node* new_node) {
    new_node->next = nullptr;
    if (!head) {
        head = new_node;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Remove a specific node from the list
void LList::remove(Node* node) {
    if (!node || !head) return;

    if (node == head) {
        head = head->next;
        delete node;
        return;
    }
    
    Node* temp = head;
    while (temp->next && temp->next != node) {
        temp = temp->next;
    }

    if (temp->next == node) {
        temp->next = node->next;
        delete node;
    }
}

// Count the number of nodes in the list
int LList::get_count() {
    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Calculate the total amount paid by all people
double LList::get_total() {
    double total = 0;
    Node* temp = head;
    while (temp) {
        total += temp->paid;
        temp = temp->next;
    }
    return total;
}

// Calculate the average amount each person should pay
double LList::get_average() {
    double total = get_total();
    int count = get_count();
    if (count == 0) return 0;
    double average = total / count;
    return average;
}

// Update each person's balance (paid - average)
void LList::update_balances() {
    double average = get_average();
    Node* temp = head;
    while (temp) {
        temp->balance = temp->paid - average;
        temp = temp->next;
    }
}

// Print out the transactions needed to balance everyone's payments
void LList::print_transactions(ostream& outs) {
    Node* payer = head;

    // First, print people who don't need to do anything (balance == 0)
    while(payer) {
        if (payer->balance == 0) {
            outs << payer->name << ", you don't need to do anything" << endl;
        }
        payer = payer->next;
    }

    // Next, for each person who owes money (balance < 0), find who to pay
    payer = head;
    while (payer) {
        if (payer->balance < 0) {
            find_receiver(outs, payer);
        }
        payer = payer->next;
    }

    // Save current formatting
    std::streamsize old_prec = outs.precision();
    std::ios_base::fmtflags old_flags = outs.flags();

    // Print the summary line with 2 decimal places, using iomanip
    outs << fixed << setprecision(2);
    outs << "In the end, you should all have spent around $" << get_average() << endl;

    // Restore previous formatting
    outs.precision(old_prec);
    outs.flags(old_flags);
}

// For a given payer (who owes money), find receivers (who are owed money) and print transactions
void LList::find_receiver(ostream& outs, Node* payer) {
    Node* receiver = head;
    while (payer->balance < 0 && receiver) {
        if (receiver->balance > 0) {
            double transfer = min(-payer->balance, receiver->balance);
            outs << payer->name << ", you give " << receiver->name << " $" << transfer << endl;
            payer->balance += transfer;
            receiver->balance -= transfer;
        }
        receiver = receiver->next; // Move to next possible receiver
    }
}

// Helper function to trim whitespace from both ends of a string, using cctype
string trim(const string& s) {
    auto start = s.begin();
    while (start != s.end() && isspace(*start)) start++;
    auto end = s.end();
    do {
        end--;
    } while (distance(start, end) > 0 && isspace(*end));
    return string(start, end + 1);
}

// Prompt the user for a filename and open the file, using fstream
void open_input_file(ifstream& infile) {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;
    infile.open(filename);
    while(!infile) {
        cout << "The file does not exist. Please enter a valid filename: ";
        cin >> filename;
        infile.clear();
        infile.open(filename);
    }
}

// Read the input file and build the linked list of people
void read_input_file(ifstream& infile, LList& bills) {
    double paid;
    string name;
    while (infile >> paid) {
        getline(infile >> ws, name); // Read the rest of the line as the name
        name = trim(name);           // Remove leading/trailing spaces
        if (name.empty()) continue;  // Skip empty lines
        bills.push_back(new Node(name, paid)); // Add to end of list
    }
    bills.update_balances(); // Calculate balances after reading all data
}

int main() {
    cout << fixed << setprecision(6); // Default: show 6 decimal places for transactions

    ifstream infile;
    LList bills;
    open_input_file(infile);      // Prompt for and open the input file
    read_input_file(infile, bills); // Read file and build linked list
    infile.close();
    bills.print_transactions(cout); // Print who owes whom

    cout << "Process finished with exit code 0" << endl; // IDE message, not required for logic

    return 0;
}