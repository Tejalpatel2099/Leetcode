class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = (int)mat.size();
        int n = (int)mat[0].size();

        // prefix sums: pre[i][j] = sum of rectangle (0,0) to (i-1,j-1)
        vector<vector<long long>> pre(m + 1, vector<long long>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pre[i][j] = mat[i - 1][j - 1]
                          + pre[i - 1][j]
                          + pre[i][j - 1]
                          - pre[i - 1][j - 1];
            }
        }

        auto squareSum = [&](int r, int c, int len) -> long long {
            int r2 = r + len, c2 = c + len;
            return pre[r2][c2] - pre[r][c2] - pre[r2][c] + pre[r][c];
        };

        auto can = [&](int len) -> bool {
            for (int r = 0; r + len <= m; r++) {
                for (int c = 0; c + len <= n; c++) {
                    if (squareSum(r, c, len) <= threshold) return true;
                }
            }
            return false;
        };

        int lo = 0, hi = min(m, n), ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (can(mid)) {
                ans = mid;      // mid works, try bigger
                lo = mid + 1;
            } else {
                hi = mid - 1;   // mid doesn't work, try smaller
            }
        }
        return ans;
    }
};