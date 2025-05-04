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
    int ans = 0;  // Variable to store the final answer (number of valid paths)

    // Main function that will be called initially
    int pathSum(TreeNode* root, int sum) {
        if (root) {
            // Try to find all paths starting from current root
            dfs(root, sum);

            // Recurse on left and right subtrees to consider new starting points
            pathSum(root->left, sum);
            pathSum(root->right, sum);
        }
        return ans;  // Return total number of valid paths found
    }

    // Helper function to count paths starting exactly from 'root' that sum to 'sum'
    void dfs(TreeNode* root, int sum) {
        if (!root) return;  // Base case: if node is null, return

        if (root->val == sum) ans++;  // Found a path with required sum

        // Continue to explore down left and right subtree reducing the required sum
        dfs(root->left, sum - root->val);
        dfs(root->right, sum - root->val);
    }
};
