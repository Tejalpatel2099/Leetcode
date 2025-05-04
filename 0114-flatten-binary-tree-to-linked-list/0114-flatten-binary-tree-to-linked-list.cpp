/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 // .....Brutr force appraoch
//  We use reverse pre-order traversal (right → left → node) to flatten the binary tree in-place into a linked list using only the right pointers.

// Steps:
// Initialize prev as null – it keeps track of the last processed node.

// Base case: If node is null, return.

// Recurse right, then left.

// Rewire current node:

// Set node.right = prev

// Set node.left = null

// Update prev = node

// This way, we start from the rightmost node and build the linked list backwards.


//.......................another apprach iterative ............
// Flatten Binary Tree using Stack (Iterative)
// This approach uses a stack to simulate recursion and flatten the tree into a right-skewed linked list.

// Steps:
// Base Case: If the root is null, return.

// Initialize Stack: Push the root onto the stack.

// Iterate While Stack Not Empty:

// Pop the top node.

// If it has a right child, push it.

// If it has a left child, push it.

// If stack is not empty, set node.right = stack.top().

// Set node.left = null (since we’re creating a linked list).

// Once done, the tree is flattened into a right-linked list.


class Solution {
private:
    TreeNode* prev = nullptr;

public:
    void flatten(TreeNode* root) {
        if (!root) return;

        flatten(root->right);  // Reverse: right first
        flatten(root->left);

        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};