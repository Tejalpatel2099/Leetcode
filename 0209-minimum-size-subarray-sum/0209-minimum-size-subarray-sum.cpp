class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
         int n = nums.size();
        int minLength = INT_MAX;
        int left = 0, sum = 0;

        for (int right = 0; right < n; ++right) {
            sum += nums[right];

            // Shrink the window while the condition is met
            while (sum >= target) {
                minLength = min(minLength, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return (minLength == INT_MAX) ? 0 : minLength;
    }
};