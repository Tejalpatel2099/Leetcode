class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        int max = amount + 1;
        std::vector<int> dp(amount + 1, max);
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (coin <= i) {
                    dp[i] = std::min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};