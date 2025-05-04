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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        recursion(root, 0, result);
        return result;
    }

private:
    void recursion(TreeNode* root, int level, vector<int>& result) {
        if (root == nullptr) return;

        // If we're visiting this level for the first time
        if (result.size() == level) {
            result.push_back(root->val);
        }

        // Visit right first to prioritize right-side view
        recursion(root->right, level + 1, result);
        recursion(root->left, level + 1, result);
    }
};
