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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;  // Final result: stores nodes level by level

        if (root == nullptr) {
            return ans;  // If the tree is empty, return empty list
        }
        map<int,vector<int>> mp;
        mp[0] = {root->val};

        queue<pair<TreeNode*, int>> q;  // first is key node and other is vertical order values 
        q.push({root, 0});        // Start BFS from the root

        while (!q.empty()) {
            TreeNode* cur = q.front().first;
            int index = q.front().second;
            q.pop();
            if (cur->left) {
                q.push({cur->left, index-1});

                if (mp.find(index-1) == mp.end()) {
                    mp[index-1] = {cur->left->val};
                }
                else {
                    mp[index-1].push_back(cur->left->val);
                }
            }

            if (cur->right) {
                q.push({cur->right, index+1});

                if (mp.find(index+1) == mp.end()) {
                    mp[index+1] = {cur->right->val};
                }
                else {
                    mp[index+1].push_back(cur->right->val);
                }
            } 
        }

         vector<vector<int>> result;
        for (auto it : mp) {
            result.push_back(it.second);
        }

        return result;
    }
};