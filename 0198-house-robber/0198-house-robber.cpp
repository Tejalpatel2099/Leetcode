class Solution {
public:
    int rob(vector<int>& nums) {
      // If only one house, return its value
        if (nums.size() < 2) 
            return nums[0];

        // Create a DP array to store the max loot at each house
        std::vector<int> dp(nums.size());

        // Initialize first two values
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);

        // Fill the DP array using recurrence relation
        for (size_t i = 2; i < nums.size(); i++) {
            dp[i] = std::max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[nums.size() - 1];
    }
};