/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int count = 0;   // Tracks how many nodes have been visited
    int result = -1; // Stores the kth smallest value once found

    // Recursive inorder traversal
    void inorder(TreeNode* root, int k) {
        if (!root || count >= k)
            return; // Base case or early stop

        inorder(root->left, k); // Visit left subtree (smaller values)

        count++;                // Visiting current node, increment count
        if (count == k) {       // If this is the kth node visited
            result = root->val; // Save the value
            return;             // Stop further traversal
        }

        inorder(root->right, k); // Visit right subtree (larger values)
    }

    // Main function to find kth smallest element
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k); // Start inorder traversal from root
        return result;    // Return the stored result
    }
};

//I use inorder traversal, which gives values in sorted order in a BST. I keep a counter, and when it reaches k, I record the current node’s value and return it.

