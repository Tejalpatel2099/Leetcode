class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<long long> dp(amount + 1, 0); // use long long to prevent overflow
        dp[0] = 1;

        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] = dp[i] + dp[i - coin];
            }
        }

        return dp[amount];
    }
};