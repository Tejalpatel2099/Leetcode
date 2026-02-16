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
    int dfs(TreeNode* node, int current) {
        if (node == nullptr) 
            return 0;
        
        // Build the current number
        current = current * 10 + node->val;
        
        // If leaf node, return the formed number
        if (node->left == nullptr && node->right == nullptr)
            return current;
        
        // Otherwise sum from left and right subtree
        return dfs(node->left, current) + dfs(node->right, current);
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};