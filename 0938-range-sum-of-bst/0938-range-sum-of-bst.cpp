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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return 0;
        }

        if (root->val < low) {
            // Skip the left subtree and only explore the right subtree.
            return rangeSumBST(root->right, low, high);
        } else if (root->val > high) {
            // Skip the right subtree and only explore the left subtree.
            return rangeSumBST(root->left, low, high);
        }
        // Node value is within the range, include it and explore both subtrees.
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};
