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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if (root == nullptr) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level(levelSize);

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                int index;
                // Insert node value at appropriate index based on direction
                //int index = leftToRight ? i : levelSize - 1 - i;
                if (leftToRight) {
                    index = i;
                } else {
                    index = levelSize - 1 - i;
                }
                level[index] = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            ans.push_back(level);
            leftToRight = !leftToRight; 
        }

        return ans;
    }
};