/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return root;
        }
        int curr = root->val;

        if(curr == p->val || curr == q->val) return root;

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left != NULL && right != NULL) return root;

        if (left == nullptr) {
            return right;
        }
        return left;

        // Below code is for binary search tree (not for binary tree)
        // if (curr < p->val && curr < q->val) {
        //     return lowestCommonAncestor(root->right, p, q);
        // }
        // if ( curr > p->val && curr > q->val) {
        //     return lowestCommonAncestor(root->left, p, q);
        // }
        // return root;
    }
       
};