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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;  // Final result: stores nodes level by level

        if (root == nullptr) {
            return ans;  // If the tree is empty, return empty list
        }

        queue<TreeNode*> q;  // Queue for BFS
        q.push(root);        // Start BFS from the root

        while (!q.empty()) {
            int size = q.size();         // Number of nodes at current level
            vector<int> level;           // Stores values for the current level

            // Process all nodes at the current level
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();  // Get front node
                q.pop();                     // Remove it from the queue

                level.push_back(node->val);  // Add its value to current level

                // Enqueue left child if exists
                if (node->left != nullptr) {
                    q.push(node->left);
                }

                // Enqueue right child if exists
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            // Add current level to the result
            ans.push_back(level);
        }

        return ans;
    }
};