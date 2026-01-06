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
    int maxLevelSum(TreeNode* root) {
        vector<vector<int>> answer;

        if (root == nullptr) {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            answer.push_back(level);
        }

        // in answer levels stored for now
        // individual levels print of answer

        int maxSum = INT_MIN;
        int result = 0;
        for (int i = 0; i < answer.size(); i++) {
            cout << "level " << i << ": ";
            int sum = 0;

            for (int j = 0; j < answer[i].size(); j++) {
                sum = sum + answer[i][j];
            }
            if (sum > maxSum) {
                maxSum = sum;
                result = i;
            }
            cout << "sum" << sum << endl;
            cout << "res" << result << endl;
        }
        return result + 1;
    }
};