class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());

        // base[n] length should be n + 1
        if (nums.size() != n + 1) {
            return false;
        }

        vector<int> count(n + 1, 0);

        for (int num : nums) {
            if (num > n) return false;
            count[num]++;
        }

        // numbers 1 to n-1 should appear once
        for (int i = 1; i < n; i++) {
            if (count[i] != 1) {
                return false;
            }
        }

        // max number n should appear twice
        if (count[n] != 2) {
            return false;
        }

        return true;
    }
};