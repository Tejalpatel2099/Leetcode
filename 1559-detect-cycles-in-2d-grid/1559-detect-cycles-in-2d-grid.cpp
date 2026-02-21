// This is a graph cycle detectiopn problem each cell is anode and we connect
// nodes if adjacent cells have same character since its is undirected i use DFS
// and trcak the paraent , if i find a visited neighbour that is not parent io
// detecrt a cycle i run dfs from evry unvisited cell
// TC ;- O(m*n)

class Solution {
public:
    
    int m, n;
    vector<vector<bool>> visited;

    // DFS function (outside containsCycle)
    bool dfs(vector<vector<char>>& grid, 
             int row, int col, 
             int parentRow, int parentCol) {

        visited[row][col] = true;

        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        for (auto &d : dirs) {
            int newRow = row + d[0];
            int newCol = col + d[1];

            // Boundary check
            if (newRow < 0 || newCol < 0 || newRow >= m || newCol >= n)
                continue;

            // Check same character
            if (grid[newRow][newCol] != grid[row][col])
                continue;

            // If not visited → DFS
            if (!visited[newRow][newCol]) {
                if (dfs(grid, newRow, newCol, row, col))
                    return true;
            }
            // If visited and not parent → cycle found
            else if (newRow != parentRow || newCol != parentCol) {
                return true;
            }
        }

        return false;
    }

    
    bool containsCycle(vector<vector<char>>& grid) {

        m = grid.size();
        n = grid[0].size();

        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (!visited[i][j]) {
                    if (dfs(grid, i, j, -1, -1))
                        return true;
                }
            }
        }

        return false;
    }
};