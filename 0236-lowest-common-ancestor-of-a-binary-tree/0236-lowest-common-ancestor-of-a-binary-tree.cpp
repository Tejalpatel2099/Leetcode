/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Approach is  recursive DFS traversal 
// i will look for P and q on the tree starting from root 
// if current node is null then i will return null 
// if current node matches either p or q 
// TC - O(N) - we visit each node once so here N is total number of nodes in binary tree
// SC- O(H) - h is height of tree (due to recursion stack)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return root;
        }

        // if root value becomes equl to p or q value then return root 
        if (root->val== p->val || root->val == q->val)
            return root;

        // Recurse into the left and right subtrees to find p and q.
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right) {
            return root;
        }
        // if p is found in one subtree, and
        // q is found in the other subtree,
        // Then the current node (root) is their lowest common ancestor. 
        else if (left != NULL && right != NULL)
            return root;
        // If only one side (left or right) returned non-null, we pass it up.
        // This means both p and q are in the same subtree, or one hasn't been
        // found yet.
        if (left == nullptr) {
            return right;
        }
        return left;

    }
};