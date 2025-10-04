// The problem asks me to find the next lexicographically greater permutation of
// a given array of integers. If no such permutation exists (like when the array
// is in descending order), I need to rearrange it into the smallest (ascending)
// permutation.
//  Brute Force Approach
//  Step 1: Generate All Permutations Using Recursion
// Use backtracking to generate all permutations of the array.
// Store them in a list.
// Sort the list of permutations.
// Find the input array’s index in that list.
//  Return the one that comes after it.
//  Tc O(n! * n) and sc - O(1)

// ..............optimized .................
// Instead of generating all permutations, I can use a mathematical observation
// based on the structure of permutations.”
// Steps (Lexicographic Algorithm):
// Find the first decreasing element from the end: index i such that nums[i] <
// nums[i + 1]. If such index doesn't exist: reverse the whole array (it's the
// last permutation). Find the next greater element than nums[i] from the end →
// index j. Swap nums[i] and nums[j]. Reverse the subarray from i + 1 to end to
// get the next smallest permutation.

// TC: - O(n) and SC:- O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = n - 2;

        // Step 1: Find the first decreasing element from the end
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            // Step 2: Find just larger element to swap
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }

        // Step 3: Reverse the rest of the array
        reverse(nums.begin() + i + 1, nums.end());
    }
};