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

        //f the current node matches either p or q, we return it.
//Why? Because a node is its own ancestor.
        int curr = root->val;

        if(curr == p->val || curr == q->val) return root;
//Recurse into the left and right subtrees to find p and q.
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

 //If:

//p is found in one subtree, and
//q is found in the other subtree,
//Then the current node (root) is their lowest common ancestor. ✅


        if(left != NULL && right != NULL) return root;


// If only one side (left or right) returned non-null, we pass it up.
//This means both p and q are in the same subtree, or one hasn't been found yet.
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