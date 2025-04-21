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
    int maxSum = INT_MIN; // To store the result (maximum path sum)

    int dfs(TreeNode* node) {
        if (!node) return 0;

        // Recurse left & right — ignore negatives by max(0, ...)
        int left = max(0, dfs(node->left));
        int right = max(0, dfs(node->right));

        // Check full path sum through current node
        int currentPathSum = node->val + left + right;

        // Update global max if needed
        maxSum = max(maxSum, currentPathSum);

        // For recursion: return max single-path upward
        return node->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
