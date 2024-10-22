class Solution {
    int matching(string &p, string &s, int i, int j, vector<vector<int>> &dp) {
        if (j < 0 && i < 0) return 1;
        if (i < 0 && j >= 0) return 0;
        if (j < 0) {
            while (i >= 0) {
                if (p[i] != '*') return 0;
                i--;
            }
            return 1;
        }
        if (dp[i][j] != -1) return dp[i][j];
        if (p[i] == s[j] || p[i] == '?') {
            return dp[i][j] = matching(p, s, i-1, j-1, dp);
        }
        if (p[i] == '*') {
            return dp[i][j] = matching(p, s, i-1, j, dp) || matching(p, s, i, j-1, dp);
        }
        return dp[i][j] = 0;
    }

public:
    bool isMatch(string s, string p) {
        int m = p.size(), n = s.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return matching(p, s, m-1, n-1, dp);
    }
};