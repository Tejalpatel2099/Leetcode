class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        // If no elements, the only subset is empty → XOR total = 0
        if (nums.empty()) return 0;

        // Key fact:
        // The sum of XORs of all subsets equals:
        //    (bitwise OR of all elements) * 2^(n-1)
        //
        // Intuition:
        // For each bit position, if that bit appears in at least one number
        // it will be set in exactly half of all subsets' XOR totals.
        // There are 2^n subsets total → contributes in 2^(n-1) subsets.

        // 1) Compute bitwise OR across all numbers to collect all present bits.
        int all_or = 0;
        for (int x : nums) {
            all_or |= x;
        }

        // 2) Multiply by 2^(n-1).
        // Use 64-bit to avoid overflow in the shift/multiplication.
        long long mul = 1LL << (nums.size() - 1);
        long long ans = (long long)all_or * mul;

        return (int)ans; // LeetCode expects int; safe for typical constraints.
    }
};