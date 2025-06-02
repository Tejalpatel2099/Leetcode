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
// Is a single-node tree considered symmetric?
// Can the tree contain duplicate values? Should symmetry be based only on structure or also on values?
//What should I return for an empty tree ?
//A binary tree is symmetric if the left subtree is a mirror of the right subtree.
//That means:
//The root values of both subtrees must be the same.
//The left child of the left subtree should match the right child of the right subtree, and vice versa — recursively.

class Solution {
private:
    // Helper function to check if two trees are mirror images of each other
    bool isMirror(TreeNode* root1, TreeNode* root2) {
        // Base case: both nodes are null, so they are mirrors
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        }
        // If only one of the nodes is null, or their values are not equal, they are not mirrors
        if (root1 == nullptr || root2 == nullptr || root1->val != root2->val) {
            return false;
        }   
        // Recursively check:
        // left child of root1 vs right child of root2
        // right child of root1 vs left child of root2
        return isMirror(root1->left, root2->right) &&
               isMirror(root1->right, root2->left);
    }

public:
    // Main function to check if a tree is symmetric
    bool isSymmetric(TreeNode* root) {
        // An empty tree is symmetric
        if (root == nullptr) {
            return true;
        }
        // Check if the left and right subtrees are mirror images
        return isMirror(root->left, root->right);
    }
};
