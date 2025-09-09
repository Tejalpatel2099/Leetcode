class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1'000'000'007;
        vector<long long> dp(n + 1, 0); // dp[d] = people who learn on day d
        dp[1] = 1;                       // day 1: one person learns
        long long share = 0;             // number of people who can share today

        for (int day = 2; day <= n; ++day) {
            // People who start sharing today: those who learned 'delay' days ago
            if (day - delay >= 1) {
                share = (share + dp[day - delay]) % MOD;
            }
            // People who forget today (cannot share anymore): learned 'forget' days ago
            if (day - forget >= 1) {
                share = (share - dp[day - forget]) % MOD;
                if (share < 0) share += MOD; // keep non-negative
            }
            // New learners today are exactly the current sharers
            dp[day] = share;
        }

        // Sum those who still remember on day n:
        // anyone who learned on day d where d >= n - forget + 1 hasn't forgotten yet.
        long long ans = 0;
        for (int d = max(1, n - forget + 1); d <= n; ++d) {
            ans = (ans + dp[d]) % MOD;
        }
        return (int)ans;
    }
};