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
    TreeNode* invertTree(TreeNode* root) {
         if (root == nullptr) return nullptr;

        // Recursively invert left and right
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);

        // Swap them
        root->left = right;
        root->right = left;

        return root;
    }
};



/*I solve this recursively by visiting each node and swapping its left and right children.
I apply the same logic to the left and right subtrees.
The base case is when the node is null, in which case I return.
Since every node is visited once, the time complexity is O(n) */