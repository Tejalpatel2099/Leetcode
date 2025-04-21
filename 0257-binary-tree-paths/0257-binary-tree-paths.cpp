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
    vector<string> result;

    void dfs(TreeNode* node, string path) {
        if (!node)
            return;

        // Add current node's value to path
        if (!path.empty()) {
            path += "->";
        }
        path += to_string(node->val);

        // If it's a leaf, add path to result
        if (!node->left && !node->right) {
            result.push_back(path);
            return;
        }

        // Recurse on left and right children
        dfs(node->left, path);
        dfs(node->right, path);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return result;
    }
};