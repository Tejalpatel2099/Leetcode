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
    unordered_map<int, int> inorderIndexMap; // To quickly find root index in inorder
    int preorderIndex = 0; // Tracks current root index in preorder

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Build the index map from inorder for O(1) lookups
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndexMap[inorder[i]] = i;
        }

        return helper(preorder, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int>& preorder, int left, int right) {
        // Base case: if left > right, no tree to build
        if (left > right) return nullptr;

        // Get the root value from preorder and move index forward
        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);

        // Find root's index in inorder
        int mid = inorderIndexMap[rootVal];

        // Build left and right subtrees recursively
        root->left = helper(preorder, left, mid - 1);
        root->right = helper(preorder, mid + 1, right);

        return root;
    }
};
