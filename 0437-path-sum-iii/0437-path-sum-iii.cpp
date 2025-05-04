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
    int ans = 0;

    int pathSum(TreeNode* root, int sum) {
        if (root) {
            dfs(root, (long long)sum);  // Cast to long long here
            pathSum(root->left, sum);
            pathSum(root->right, sum);
        }
        return ans;
    }

    void dfs(TreeNode* root, long long sum) {
        if (!root) return;
        if ((long long)root->val == sum) ans++;
        dfs(root->left, sum - root->val);
        dfs(root->right, sum - root->val);
    }
};
