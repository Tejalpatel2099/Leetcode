class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
    for (int x : nums) total += x;

    // If total sum is odd, we can’t split into two equal sums
    if (total % 2 != 0) return false;

    int target = total / 2;

    // dp[s] = can we make sum s using some elements?
    vector<bool> dp(target + 1, false);
    dp[0] = true;  // sum 0 is always possible

    for (int x : nums) {
        // go backwards so each number is used only once
        for (int s = target; s >= x; s--) {
            if (dp[s - x]) dp[s] = true;
        }
        // small optimization: if we already can make target, stop early
        if (dp[target]) return true;
    }

    return dp[target];
    }
};