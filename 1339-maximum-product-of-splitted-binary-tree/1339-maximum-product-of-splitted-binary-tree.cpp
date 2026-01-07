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
    long long totalSum = 0;
    long long best = 0;
    const int MOD = 1e9 + 7;

    // 1) Get total sum of the tree
    long long getTotal(TreeNode* root) {
        if (!root) return 0;
        return root->val + getTotal(root->left) + getTotal(root->right);
    }

    // 2) Postorder: compute subtree sums, update best product
    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long subSum = root->val + left + right;

        // If we cut the edge above this subtree:
        // one part = subSum, other part = totalSum - subSum
        best = max(best, subSum * (totalSum - subSum));

        return subSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = getTotal(root);  // pass 1
        dfs(root);                  // pass 2 (updates best)
        return (int)(best % MOD);
    }
};