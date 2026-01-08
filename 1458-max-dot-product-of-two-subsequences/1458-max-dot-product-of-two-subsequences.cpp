class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = (int)nums1.size();
        int m = (int)nums2.size();

        // Use a very small number as -infinity (since products can be negative).
        const int NEG_INF = -1e9;

        // dp[i][j] = max dot product using subsequences from nums1[0..i-1] and nums2[0..j-1]
        // (i and j are lengths). Answer is dp[n][m].
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, NEG_INF));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int prod = nums1[i - 1] * nums2[j - 1];

                // Option 1: Start a new subsequence with just this pair (important for all-negative cases)
                int takeOnly = prod;

                // Option 2: Extend a previous best subsequence (if it exists)
                int extend = (dp[i - 1][j - 1] == NEG_INF) ? NEG_INF : dp[i - 1][j - 1] + prod;

                // Option 3: Skip nums1[i-1]
                int skip1 = dp[i - 1][j];

                // Option 4: Skip nums2[j-1]
                int skip2 = dp[i][j - 1];

                dp[i][j] = max({takeOnly, extend, skip1, skip2});
            }
        }

        return dp[n][m];
    }
};