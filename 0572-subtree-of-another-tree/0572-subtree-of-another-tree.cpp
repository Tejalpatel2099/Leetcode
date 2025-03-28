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
private: 
    // Utility function to check if two trees are identical
bool isIdentical(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr && root2 == nullptr)
        return true;
    if (root1 == nullptr || root2 == nullptr)
        return false;

    // Check if data and left/right subtrees are identical
    return (root1->val == root2->val &&
            isIdentical(root1->left, root2->left) &&
            isIdentical(root1->right, root2->right));
}
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == nullptr) {
            return 1;
        }
        if (root == nullptr) {
            return 0;
        }
        if (isIdentical(root, subRoot)) {
            return 1;
        }
        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));  // if identical check left and right subtree.
    }
};