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
    vector<int> list;
    void inorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left);
        list.push_back(root->val);
        inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        for (int i = 1; i < list.size(); i++) {
            if (list[i] <= list[i - 1]) {
                return false;
            }
        }
        return true;
    }
};