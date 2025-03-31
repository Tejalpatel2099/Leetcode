class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num_islands = 0;
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    num_islands++;
                    dfs(grid, i, j, rows, cols);
                }
            }
        }
        return num_islands;
    }

private:
    void dfs(vector<vector<char>>& grid, int i, int j, int rows, int cols) {
        if (i < 0 || i == rows || j < 0 || j == cols || grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0'; // Mark as visited

        dfs(grid, i + 1, j, rows, cols); // down
        dfs(grid, i - 1, j, rows, cols); // up
        dfs(grid, i, j + 1, rows, cols); // right
        dfs(grid, i, j - 1, rows, cols); // left
    }
};
