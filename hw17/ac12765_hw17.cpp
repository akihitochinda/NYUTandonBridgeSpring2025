/*
Homework 17: Red Black Tree
    In this assignment, you will complete the code for insertions in a Red-Black tree. We've
provided a framework with comments. You should complete the sections labeled "TODO"

    You are also required to follow any directions accompanying comments such as "NOTE".
You can add/modify code anywhere, with the exception of the provided "main" (which we will
use for testing). You can use the constants RED and BLACK, instead of the ints 0 and 1, when
appropriate.
*/

#include <iostream>
#include <math.h> // for asserting height
#include <queue>
#include <cassert>

using namespace std;

#define RED 0
#define BLACK 1

template <class T>
class RBT;

// swapColor swaps the color from red to black and vice versa
int swapColor(int c) {
    return (c==0)?1:0;
}

template <class T>
class RBTNode {
    RBTNode<T> *parent, *left, *right;
    T data;
    int color;

public:
    RBTNode(T data)
        : data(data),
          color(RED),
          parent(nullptr),
          left(nullptr),
          right(nullptr) {}
    friend class RBT<T>;
    void prettyPrint(int indent) const;

    template <class T1>
    friend void swapColor(RBTNode<T1> *);
    template <class T1>
    friend int getColor(RBTNode<T1> *);

    int height() const;
};

template <class T>
int RBTNode<T>::height() const {
    int left_h = 0;
    if (left != nullptr) {
        left_h = left->height();
    }
    int right_h = 0;
    if (right != nullptr) {
        right_h = right->height();
    }
    return 1 + max(left_h, right_h);
}

template <class T>
void RBTNode<T>::prettyPrint(int indent) const {
    if (right != nullptr) {
        right->prettyPrint(indent + 1);
    }
    int margin = indent * 2;
    for (int i = 0; i < margin; ++i) {
        cout << '\t';
    }
    cout << "DATA: " << data << endl;
    for (int i = 0; i < margin; ++i) {
        cout << '\t';
    }
    cout << "COLOR: " << (color == RED ? "RED" : "BLACK") << endl;
    if (left != nullptr) {
        left->prettyPrint(indent + 1);
    }
}

template <class T>
void swapColor(RBTNode<T> *node) {
    if (node != nullptr) {
        node->color = swapColor(node->color);
    }
}

// getColor handles null nodes
template <class T>
int getColor(RBTNode<T> *node) {
    if (node != nullptr) {
        return node->color;
    }
    return BLACK;
}

template <class T>
class RBT {
    RBTNode<T> *root;
    void singleCCR(RBTNode<T> *&point);
    void doubleCR(RBTNode<T> *&point);
    void singleCR(RBTNode<T> *&point);
    void doubleCCR(RBTNode<T> *&point);

public:
    RBT() : root(nullptr) {}

    void insert(const T &);
    void insert(const T &, RBTNode<T> *&point, RBTNode<T> *parent);
    void prettyPrint() const { root->prettyPrint(0); }

    int height() const { return root->height(); }
};

template <class T>
void RBT<T>::doubleCCR(RBTNode<T> *&point) {
    singleCR(point->right);
    singleCCR(point);
}

template <class T>
void RBT<T>::doubleCR(RBTNode<T> *&point) {
    singleCCR(point->left);
    singleCR(point);
}

template <class T>
void RBT<T>::singleCR(RBTNode<T> *&point) {
    RBTNode<T> *grandparent = point;
    RBTNode<T> *parent = point->left;
    // TODO: ADD ROTATION CODE HERE
    // --- Single Clockwise Rotation (Right Rotation) ---
    // This rotation is used when a left child (parent) has a left child (curr_node)
    // and a violation occurs (two consecutive reds).
    // The parent becomes the new root of this subtree, and the grandparent becomes the right child of the parent.
    // The parent's right subtree becomes the grandparent's left subtree.
    grandparent->left = parent->right;
    if (parent->right != nullptr) {
        parent->right->parent = grandparent; // Update the parent pointer of the moved subtree
    }

    RBTNode<T> *great_grandparent = grandparent->parent; // Get the great-grandparent
    parent->parent = great_grandparent; // Update the parent's parent pointer

    // Update the parent's parent pointer to point to the correct child of the great-grandparent
    if (great_grandparent == nullptr) {
        root = parent; // If there's no great-grandparent, update the root
    } else if (grandparent == great_grandparent->left) {
        great_grandparent->left = parent; // Update the left child of the great-grandparent
    } else {
        great_grandparent->right = parent; // Update the right child of the great-grandparent
    }

    parent->right = grandparent;
    grandparent->parent = parent;
}

template <class T>
void RBT<T>::singleCCR(RBTNode<T> *&point) {
    RBTNode<T> *grandparent = point;
    RBTNode<T> *parent = point->right;
    // TODO: ADD ROTATION CODE HERE
    // --- Single Counter-Clockwise Rotation (Left Rotation) ---
    // This rotation is used when a right child (parent) has a right child (curr_node)
    // and a violation occurs (two consecutive reds).
    // The parent becomes the new root of this subtree, and the grandparent becomes the left child of the parent.
    // The parent's left subtree becomes the grandparent's right subtree.
    grandparent->right = parent->left;
    if (parent->left != nullptr) {
        parent->left->parent = grandparent; // Update the parent pointer of the moved subtree
    }

    RBTNode<T> *great_grandparent = grandparent->parent; // Get the great-grandparent
    parent->parent = great_grandparent; // Update the parent's parent pointer

    // Update the parent's parent pointer to point to the correct child of the great-grandparent
    if (great_grandparent == nullptr) {
        root = parent; // If there's no great-grandparent, update the root
    } else if (grandparent == great_grandparent->left) {
        great_grandparent->left = parent; // Update the left child of the great-grandparent
    } else {
        great_grandparent->right = parent; // Update the right child of the great-grandparent
    }

    parent->left = grandparent;
    grandparent->parent = parent;
}

template <class T>
void RBT<T>::insert(const T &toInsert, RBTNode<T> *&point, RBTNode<T> *parent) {
    if (point == nullptr) {               // leaf location is found so insert node
        point = new RBTNode<T>(toInsert); // modifies the pointer itself since *point
                                          // is passed by reference
        point->parent = parent;

        RBTNode<T> *curr_node = point; // curr_node will be set appropriately when walking up the tree
        // TODO: ADD RBT RULES HERE
        // --- Red-Black Tree Fix-Up Logic ---
        // After inserting a red node, we need to restore RBT properties.
        // If the parent is also red, this creates a violation (no two consecutive reds allowed).
        // We walk up the tree, fixing violations by recoloring and/or rotating as needed.
        while (curr_node!=root && parent->color == RED) {
            RBTNode<T> *grandparent = parent->parent;
            if (parent == grandparent->left) { // parent is left child of grandparent
                RBTNode<T> *uncle = grandparent->right; // Get the uncle
                if (uncle!= nullptr && uncle->color == RED) {
                    // Case 1: Uncle is red
                    // Recolor parent, uncle, and grandparent
                    swapColor(uncle);
                    swapColor(parent);
                    swapColor(grandparent);
                    // Move up the tree and continue fixing
                    curr_node = grandparent;
                    parent = curr_node->parent;
                } else {
                    // Case 2 & 3: Uncle is black or null
                    // If curr_node is a right child, do a left rotation on parent
                    if (curr_node == parent->right) {
                        singleCCR(parent);
                    } 
                    // Then do a right rotation on grandparent
                    singleCR(grandparent);
                    // After rotation, recolor parent and grandparent
                    swapColor(grandparent);
                    swapColor(parent);
                }
            } else { // parent is right child of grandparent
                RBTNode<T> *uncle = grandparent->left; // Get the uncle
                if (uncle != nullptr && uncle->color == RED) {
                    // Case 1: Uncle is red
                    // Recolor parent, uncle, and grandparent
                    swapColor(uncle);
                    swapColor(parent);
                    swapColor(grandparent);
                    // Move up the tree and continue fixing
                    curr_node = grandparent;
                    parent = curr_node->parent;
                } else {
                    // Case 2 & 3: Uncle is black or null
                    // If curr_node is a left child, do a right rotation on parent
                    if (curr_node == parent->left) {
                        singleCR(parent);
                    }
                    // Then do a left rotation on grandparent
                    singleCCR(grandparent);
                    // After rotation, recolor parent and grandparent
                    swapColor(grandparent);
                    swapColor(parent);
                }
            }
        }
        // Always ensure the root is black
        root->color = BLACK;
    } else if (toInsert < point->data) { // recurse down the tree to left to find correct leaf location
        insert(toInsert, point->left, point);
    } else { // recurse down the tree to right to find correct leaf location
        insert(toInsert, point->right, point);
    }
}

template <class T>
void RBT<T>::insert(const T &toInsert) {
    insert(toInsert, root, nullptr);
}

// NOTE: DO NOT MODIFY THE MAIN FUNCTION BELOW
int main() {
    RBT<int> b;
    int count = 10;
    for (int i = 0; i < count; i++) {
        b.insert(i);
    }
    b.prettyPrint();
    /* EXPECTED OUTPUT:
                                                                    Data: 9
                                                                    COLOR: RED
                                                    Data: 8
                                                    COLOR: BLACK
                                    Data: 7
                                    COLOR: RED
                                                    Data: 6
                                                    COLOR: BLACK
                    Data: 5
                    COLOR: BLACK
                                    Data: 4
                                    COLOR: BLACK
    Data: 3
    COLOR: BLACK
                                    Data: 2
                                    COLOR: BLACK
                    Data: 1
                    COLOR: BLACK
                                    Data: 0
                                    COLOR: BLACK
    */
    // TEST
    // the below tests the validity of the height of the RBT
    // if the assertion fails, then your tree does not properly self-balance
    int height = b.height();
    assert(height <= 2 * log2(count));
    cout<<endl;
    cout<<"---------------------"<<endl;
    cout<<endl;
    RBT<int> c;
    count = 5;
    for (int i = count; i > 0; i--) {
        c.insert(i);
    }
    c.prettyPrint();
    /* EXPECTED OUTPUT:
                    Data: 5
                    COLOR: BLACK
    Data: 4
    COLOR: BLACK
                                    Data: 3
                                    COLOR: RED
                    Data: 2
                    COLOR: BLACK
                                    Data: 1
                                    COLOR: RED
    */
    height = c.height();
    assert(height <= 2 * log2(count));
}
