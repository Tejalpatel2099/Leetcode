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


 // add root (if root is not leaf) 
 // Traverse left boundry 
 // add all leavces 
 // traverse right boundry and then store the values and after that i will reverse it 
 // anticlockwise order 
 // Time: O(N) — each node visited once.
 // Sc - Space: O(H) — recursion depth + few vectors. 
class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        if (!isLeaf(root)) ans.push_back(root->val);  // root (not leaf)

        addLeftBoundary(root->left, ans);   // left boundary (excluding leaves)
        addLeaves(root, ans);               // all leaf nodes
        addRightBoundary(root->right, ans); // right boundary (in reverse)

        return ans;
    }

private:
    bool isLeaf(TreeNode* node) {
        return node && !node->left && !node->right;
    }

    void addLeftBoundary(TreeNode* node, vector<int>& ans) {
        while (node) {
            if (!isLeaf(node)) ans.push_back(node->val);
            if (node->left) node = node->left;
            else node = node->right;
        }
    }

    void addRightBoundary(TreeNode* node, vector<int>& ans) {
        vector<int> temp;
        while (node) {
            if (!isLeaf(node)) temp.push_back(node->val);
            if (node->right) node = node->right;
            else node = node->left;
        }
        // Add in reverse order
        for (int i = temp.size() - 1; i >= 0; i--)
            ans.push_back(temp[i]);
    }

    void addLeaves(TreeNode* node, vector<int>& ans) {
        if (!node) return;
        if (isLeaf(node)) {
            ans.push_back(node->val);
            return;
        }
        addLeaves(node->left, ans);
        addLeaves(node->right, ans);
    }
};