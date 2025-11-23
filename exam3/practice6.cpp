/*
14. Given the struct, implement the following functions:
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
};

// Given two binary trees, write a function to check if they are the same or not.
// Two binary trees are considered the same if they are structurally identical
// and the nodes have the same value.
bool isSameTree(TreeNode* p, TreeNode* q) {
    // Base case: if either node is null, both must be null to be the same
    if (p == nullptr || q == nullptr) return (p == q);
    // Check current node values and recursively check left and right subtrees
    return (p->val == q->val && isSameTree(p->left, q->left) &&
        isSameTree(p->right, q->right));
}

// Given a binary tree, check whether it is a mirror of itself
// (ie, symmetric around its center).
bool isSymmetricHelp(TreeNode* left, TreeNode* right){
    // If either node is null, both must be null to be symmetric
    if (left == nullptr || right == nullptr)
        return left == right;
    // Values must match, and left's left must mirror right's right, etc.
    if (left->val != right->val)
        return false;
    return isSymmetricHelp(left->left, right->right)
        && isSymmetricHelp(left->right, right->left);
}
bool isSymmetric(TreeNode* root) {
    // An empty tree is symmetric, otherwise check mirror property
    return root == nullptr || isSymmetricHelp(root->left, root->right);
}

// Given a binary tree, implement level order traversal
// you can also change this to void by just logging out the numbers as you see them
/*
void levelOrder(TreeNode* root) {
    // TODO
    // If the tree is empty (root == nullptr), return.
    if (root == nullptr) return;

    // We're going to use a queue to store the nodes
    queue<TreeNode*> q; // A queue q is used for breadth-first traversal.
    q.push(root); // Push the root node into the queue.

    while (!q.empty()) {
        TreeNode* node = q.front(); // Get the current node from the front of the queue.
        q.pop(); // Remove the current node from the queue.

        // Process the current node (e.g., print its value).
        cout << node->val << " ";

        // Add the left and right children to the queue if they exist.
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }

    cout << endl;
}
*/
// This function performs a breadth-first (level order) traversal of a binary tree,
// collecting the values at each level into a separate vector, and returns a vector of these vectors.
// The use of nullptr as a delimiter helps to detect when a level ends.

// Returns a vector of vectors, each inner vector is a level of the tree
vector<vector<int>> levelOrder(TreeNode* root) {
// TODO
    vector<vector<int>> result;
    if (!root) return result; // If the tree is empty (root == nullptr), return an empty result.

    queue<TreeNode*> q; // A queue q is used for breadth-first traversal.
    q.push(root); // Push the root node into the queue.
    q.push(nullptr); // Push a nullptr as a level delimiter to mark the end of the first level.

    vector<int> cur_vec;
    while(!q.empty()) {
        TreeNode* t = q.front(); // Get the current node from the queue into t.
        q.pop(); // Remove the current node from the queue
        if (t== nullptr) {
            // End of current level
            result.push_back(cur_vec); // Push the current level's vector (cur_vec) into result.
            cur_vec.resize(0); // Clear cur_vec for the next level.
            if (q.size() > 0) { // If there are more nodes to process
                q.push(nullptr); // push another nullptr to mark the end of the next level.
            }
        } else {
            // If t is not nullptr
            cur_vec.push_back(t->val); // Add node value to current level
            if (t->left) q.push(t->left);   // Queue left child
            if (t->right) q.push(t->right); // Queue right child
        }
    }
    return result;
}

int main() {
    // Build two identical trees
    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(2);
    t1->left->left = new TreeNode(3);
    t1->left->right = new TreeNode(4);
    t1->right->left = new TreeNode(4);
    t1->right->right = new TreeNode(3);

    TreeNode* t2 = new TreeNode(1);
    t2->left = new TreeNode(2);
    t2->right = new TreeNode(2);
    t2->left->left = new TreeNode(3);
    t2->left->right = new TreeNode(4);
    t2->right->left = new TreeNode(4);
    t2->right->right = new TreeNode(3);

    // Build a different tree
    TreeNode* t3 = new TreeNode(1);
    t3->left = new TreeNode(2);
    t3->right = new TreeNode(3);
    t3->left->left = new TreeNode(4);
    t3->right->left = new TreeNode(5);
    t3->right->right = new TreeNode(6);

    // Test isSameTree
    cout << "t1 and t2 are the same tree? " << (isSameTree(t1, t2) ? "Yes" : "No") << endl;
    cout << "t1 and t3 are the same tree? " << (isSameTree(t1, t3) ? "Yes" : "No") << endl;

    // Test isSymmetric
    cout << "t1 is symmetric? " << (isSymmetric(t1) ? "Yes" : "No") << endl;
    cout << "t3 is symmetric? " << (isSymmetric(t3) ? "Yes" : "No") << endl;

    // Test levelOrder
    auto levels = levelOrder(t1);
    cout << "Level order traversal of t1:" << endl;
    for (const auto& level : levels) {
        for (int v : level) cout << v << " ";
        cout << endl;
    }

    levels = levelOrder(t3);
    cout << "Level order traversal of t3:" << endl;
    for (const auto& level : levels) {
        for (int v : level) cout << v << " ";
        cout << endl;
    }

    return 0;
}