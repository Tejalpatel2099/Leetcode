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
class Solution {
public:
    int diameter = 0; // Stores the maximum diameter found so far

    // Recursive function to compute the depth of a subtree
    int depth(TreeNode* node) {
        if (!node) return 0; // Base case: empty subtree has depth 0

        int leftDepth = depth(node->left);   // Recursively find depth of left subtree
        int rightDepth = depth(node->right); // Recursively find depth of right subtree

        // The path through this node = left depth + right depth
        diameter = max(diameter, leftDepth + rightDepth); // Update max diameter if needed

        // Return the depth of the current subtree = 1 (current node) + max of left/right
        return 1 + max(leftDepth, rightDepth);
    }

    // Main function to compute the diameter of the binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);        // Start depth-first search from the root
        return diameter;    // Return the maximum diameter found
    }
};

// the diameter is sum of depth of left and right subtree at any node 
// for each node we left depth and right depth update the diameter as left + right 
// recursively do for each node and keep track of maximium diameter. 