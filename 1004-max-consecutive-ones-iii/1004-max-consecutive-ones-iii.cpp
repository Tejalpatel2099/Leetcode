class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int zeros = 0;
        int best = 0;

        for (int r = 0; r < (int)nums.size(); r++) {
            if (nums[r] == 0) zeros++;

            while (zeros > k) {
                if (nums[l] == 0) zeros--;
                l++;
            }

            best = max(best, r - l + 1);
        }

        return best;
    }
};