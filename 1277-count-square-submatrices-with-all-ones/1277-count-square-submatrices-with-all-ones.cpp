class Solution {
private:
    // 2D DP array to store results of subproblems
    int dp[301][301];

    // Recursive function to solve for each cell (i, j)
    int solve(int n, int m, vector<vector<int>>& matrix, int i, int j){
        // Base case: out of bounds or cell is 0
        if(i < 0 || i >= n || j < 0 || j >= m || matrix[i][j] == 0) return 0;

        // Return memoized result if already calculated
        if(dp[i][j] != -1) return dp[i][j];

        // Recursively calculate the size of the square submatrix
        int right = solve(n, m, matrix, i, j + 1);
        int down = solve(n, m, matrix, i + 1, j);
        int diagonal = solve(n, m, matrix, i + 1, j + 1);

        // The size of the square submatrix ending at (i, j)
        dp[i][j] = 1 + min({right, down, diagonal});

        // Return the calculated result
        return dp[i][j];
    }

public:
    int countSquares(vector<vector<int>>& matrix) {
        // Initialize DP array with -1 (not calculated state)
        memset(dp, -1, sizeof(dp));

        int n = matrix.size();    // Number of rows
        int m = matrix[0].size(); // Number of columns
        int ans = 0;              // To store the final count of squares

        // Traverse each cell in the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If the cell is 1, calculate the number of squares ending at (i, j)
                if(matrix[i][j] == 1){
                    ans += solve(n, m, matrix, i, j);
                }
            }
        }

        return ans; // Return the total number of square submatrices
    }
};