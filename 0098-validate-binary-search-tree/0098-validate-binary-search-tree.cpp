//To validate a BST, it’s not enough to just check the left and right child. We must ensure that all nodes in the left subtree are < node.val, and all in the right are > node.val.So, I use recursion and pass down a (min, max) range. Each node must lie within this range. As we go left, we shrink the upper bound; as we go right, we raise the lower bound.This ensures every node is validated in the context of the full tree.


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
    // Main function to check if a binary tree is a valid Binary Search Tree (BST)
    bool isValidBST(TreeNode* root) {
        // Call the helper function with initial valid range (-∞ to ∞)
        return helper(root, LONG_MIN, LONG_MAX);
    }

    // Helper function to recursively check BST validity
    // node   - current node being checked
    // minVal - the minimum value the current node is allowed to have
    // maxVal - the maximum value the current node is allowed to have
    bool helper(TreeNode* node, long minVal, long maxVal) {
        // Base case: if node is null, it's valid (empty trees are valid BSTs)
        if (!node) return true;

        // If the current node's value is outside the allowed range, it's not a BST
        if (node->val <= minVal || node->val >= maxVal)
            return false;

        // Recursively check the left subtree:
        // All values must be less than the current node's value
        // So update maxVal to node->val
        bool leftIsValid = helper(node->left, minVal, node->val);

        // Recursively check the right subtree:
        // All values must be greater than the current node's value
        // So update minVal to node->val
        bool rightIsValid = helper(node->right, node->val, maxVal);

        // Return true only if both left and right subtrees are valid
        return leftIsValid && rightIsValid;
    }
};