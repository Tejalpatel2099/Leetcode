// Given a 2D grid where 1 represents land and 0 represents water, I need to
// count how many distinct islands there are. An island is formed by connecting
// adjacent 1s either horizontally or vertically. So, I need to explore each
// group of connected 1s and count how many such groups exist. Question s:-
// 1. Can the grid be empty or null?
// 2. Can diagonals connections form a island?
// 3. Can i modify the input array to avoid using additional space?

// The moment I see a 1 that is part of land, I can start a DFS (or BFS) to
// flood fill and mark the entire island so I don’t count it again. I repeat
// this for every unvisited land cell. traverse teh grid using nested loops and
// evry time I find a 1 it is new island. SO i will increment the island count
// and run dfs from that cell to mark all connected land as visited.and will
// continue checking rest of grid.
// ime: O(m × n) — Each cell is visited once.
// Space: O(m × n) for recursion stack in worst-case (for DFS)

class Solution {
public:
    // Main function to count number of islands
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;

        int m = grid.size();    // Number of rows
        int n = grid[0].size(); // Number of columns
        int count = 0;          // Island counter

        // Traverse each cell in the grid
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {

                // If we find land ('1'), it's a new island
                if (grid[i][j] == '1') {
                    count++;         // Increment island count
                    dfs(grid, i, j); // Start DFS to mark entire island
                }
            }
        }

        return count; // Return the total number of islands
    }
    // Helper function to perform DFS and mark the visited land
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();    // Number of rows
        int n = grid[0].size(); // Number of columns

        // Check for boundary conditions and water or already visited cells
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0') {
            return;
        }

        // Mark the current cell as visited by setting it to '0' (water)
        grid[i][j] = '0';

        // Visit all 4 connected directions: up, down, left, right
        dfs(grid, i + 1, j); // down
        dfs(grid, i - 1, j); // up
        dfs(grid, i, j + 1); // right
        dfs(grid, i, j - 1); // left
    }
};
