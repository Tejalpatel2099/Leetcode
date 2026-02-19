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
    vector<TreeNode*> nodes;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        nodes.push_back(root);
        inorder(root->right);
    }

    TreeNode* build(int l, int r) {
        if (l > r) return nullptr;

        int mid = l + (r - l) / 2;
        TreeNode* root = nodes[mid];

        root->left  = build(l, mid - 1);
        root->right = build(mid + 1, r);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        nodes.clear();
        inorder(root);
        return build(0, (int)nodes.size() - 1);
    }
};
