

class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> col(n, false);           // columns
        vector<bool> diag1(2*n - 1, false);   // (r - c + n - 1)
        vector<bool> diag2(2*n - 1, false);   // (r + c)
        int ans = 0;

        dfs(0, n, col, diag1, diag2, ans);
        return ans;
    }

private:
    void dfs(int r, int n, vector<bool>& col, vector<bool>& diag1, vector<bool>& diag2, int& ans) {
        if (r == n) {        // placed queens in all rows
            ans++;
            return;
        }

        for (int c = 0; c < n; c++) {
            int d1 = r - c + n - 1;
            int d2 = r + c;

            if (col[c] || diag1[d1] || diag2[d2]) continue;

            col[c] = diag1[d1] = diag2[d2] = true;
            dfs(r + 1, n, col, diag1, diag2, ans);
            col[c] = diag1[d1] = diag2[d2] = false; // backtrack
        }
    }
};
