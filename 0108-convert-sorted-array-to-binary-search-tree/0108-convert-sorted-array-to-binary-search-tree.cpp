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
private:
    TreeNode* convertBST(int left, int right, vector<int>& arr)
    {
        /* if i dont have any element in array then my right becomes -1 cause my right is my size and my size is 0 - 1 means -1 so from that i can say i don't have element and return nullptr.
        */
        if(left > right)
        {
            return nullptr;
        }
        // calculate the value of mid
        /*
           we write left + ((right - left) / 2) cause at some point if we write (left + right) / 2 will go outside of my  integer if my left and right both are big number in that case this type of probelm is occurs so for that we use     that left + ((right - left) / 2) both gives same answer
        */
        int mid = left + ((right - left) / 2);
        // creating new tree and put mid value at root node
        TreeNode* root = new TreeNode(arr[mid]);
        /* in left size node we have to put the value of left side
           array and for that we are going left in tree and we put
           mid - 1 value from array and we are calling this function
           recursively
        */
        root -> left = convertBST(left, mid - 1, arr);
        /* in right size node we have to put the value of right side
           array and for that we are going right in tree and we put
           mid + 1 value from array and we are calling this function
           recursively
        */
        root -> right = convertBST(mid + 1, right, arr);
        // at the end we are returning the root(means whole tree)
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // fetching size of the array nums
        int size = nums.size() - 1;
        return convertBST(0, size, nums);
    }
};