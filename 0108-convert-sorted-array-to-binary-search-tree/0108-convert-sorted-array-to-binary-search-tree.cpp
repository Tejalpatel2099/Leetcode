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

//Pick the middle element of the array (or subarray) — this becomes the root.
//Recursively:
//Build the left subtree from the left half
//Build the right subtree from the right half
//Base case: if start > end, return nullptr.




class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }

private:
    // Helper function for recursive construction
    TreeNode* buildBST(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;  // Base case: empty range

        int mid = left + (right - left) / 2;  // Choose middle element to avoid overflow
        TreeNode* root = new TreeNode(nums[mid]);  // Mid becomes root

        // Recursively build left and right subtrees
        root->left = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);

        return root;
    }
}