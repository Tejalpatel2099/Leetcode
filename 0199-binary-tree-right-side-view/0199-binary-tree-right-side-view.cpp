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

        // If we're visiting this level for the first time,this is the first node seen at this level, and due to right-first traversal, it's the rightmost.
        if (result.size() == level) {
            result.push_back(root->val);
        }

        // Visit right first to prioritize right-side view
        recursion(root->right, level + 1, result);
        recursion(root->left, level + 1, result);
    }
};


//“This recursive DFS approach visits right nodes before left.
//For each level, the first node we visit is the rightmost one, and we add it to the result.
//We track the level and only add a value when we first reach a new level.
//It’s an efficient in-place O(n) time, O(h) space solution.