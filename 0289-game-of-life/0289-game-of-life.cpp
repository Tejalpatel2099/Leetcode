class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();        // number of rows
        int n = board[0].size();     // number of columns

        // Make a copy of the board to refer to the original states
        vector<vector<int>> temp = board;

        // All 8 possible directions (neighbors)
        int dirs[8][2] = {
            {-1, -1}, {-1, 0}, {-1, 1},
            { 0, -1},          { 0, 1},
            { 1, -1}, { 1, 0}, { 1, 1}
        };

        // Go through each cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int liveNeighbors = 0;

                // Check all 8 neighbors
                for (int k = 0; k < 8; k++) {
                    int ni = i + dirs[k][0]; // new row
                    int nj = j + dirs[k][1]; // new column

                    // Check boundaries (should be inside the board)
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        if (temp[ni][nj] == 1) {
                            liveNeighbors++;
                        }
                    }
                }

                // Apply the Game of Life rules

                // Rule 1: Live cell with fewer than 2 live neighbors dies
                if (temp[i][j] == 1 && liveNeighbors < 2) {
                    board[i][j] = 0;
                }
                // Rule 2: Live cell with 2 or 3 live neighbors stays alive
                else if (temp[i][j] == 1 && (liveNeighbors == 2 || liveNeighbors == 3)) {
                    board[i][j] = 1;
                }
                // Rule 3: Live cell with more than 3 live neighbors dies
                else if (temp[i][j] == 1 && liveNeighbors > 3) {
                    board[i][j] = 0;
                }
                // Rule 4: Dead cell with exactly 3 live neighbors becomes alive
                else if (temp[i][j] == 0 && liveNeighbors == 3) {
                    board[i][j] = 1;
                }
                // Otherwise, keep it dead
                else if (temp[i][j] == 0) {
                    board[i][j] = 0;
                }
            }
        }
    }
};
