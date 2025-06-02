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

 //Are both trees guaranteed to be binary trees?
 //Can either or both trees be empty (i.e., null)?
 // Are the node values integers?
 //I will solve this using recursion. The idea is to traverse both trees at the same time and compare each corresponding pair of nodes. If at any point: tne node is null and the other isn't, or both are not null but have different values, then the trees are not the same.
//If both nodes are null at the same position or if all corresponding node values match and subtrees match, then the trees are identical

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base cases
        if (!p && !q) return true;           // both are null
        if (!p || !q) return false;          // one is null, one is not
        if (p->val != q->val) return false;  // values don't match

        // Recursively check left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

//Time	O(n)	We visit each node once, where n = number of nodes
//Space (stack)	O(h)	Due to recursion call stack, where h = height of the tree
