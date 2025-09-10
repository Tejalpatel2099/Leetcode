class Solution {
 // Bitmasks: rows[i], cols[j], boxes[k] hold used digits for that unit.
    // Bit k (0..8) set => digit (k+1) is already used.
    int rows[9]{}, cols[9]{}, boxes[9]{};
    vector<pair<int,int>> emptyCells; // positions of '.'
    
    inline int boxId(int r, int c) { return (r/3)*3 + (c/3); }
    
    // Count bits set (used to pick the cell with minimum remaining values)
    inline int popcount(int x) { return __builtin_popcount((unsigned)x); }
    
    // Try to fill cells starting from 'idx' in emptyCells (but we choose the best next each time).
    bool dfs(vector<vector<char>>& board) {
        if (emptyCells.empty()) return true; // all filled
        
        // MRV: choose the empty cell with the fewest candidates
        int bestIdx = -1, bestCount = 10, candMaskForBest = 0;
        for (int i = 0; i < (int)emptyCells.size(); ++i) {
            auto [r, c] = emptyCells[i];
            int m = rows[r] | cols[c] | boxes[boxId(r,c)];
            int candidates = (~m) & 0x1FF;                // bits for digits 1..9 available
            int cnt = popcount(candidates);
            if (cnt == 0) return false;                   // dead end
            if (cnt < bestCount) {
                bestCount = cnt;
                bestIdx = i;
                candMaskForBest = candidates;
                if (cnt == 1) break;                      // can't do better
            }
        }
        
        // Work on the chosen cell
        auto [r, c] = emptyCells[bestIdx];
        int b = boxId(r, c);
        // Temporarily remove from list (swap-pop)
        swap(emptyCells[bestIdx], emptyCells.back());
        emptyCells.pop_back();
        
        // Try each candidate digit
        for (int m = candMaskForBest; m; m &= (m-1)) {
            int bit = m & -m;                // lowest set bit
            int d = __builtin_ctz(bit);      // 0..8  => digit = d+1
            // place
            board[r][c] = char('1' + d);
            rows[r]   |= bit;
            cols[c]   |= bit;
            boxes[b]  |= bit;
            
            if (dfs(board)) return true;     // solved
            
            // undo
            rows[r]   &= ~bit;
            cols[c]   &= ~bit;
            boxes[b]  &= ~bit;
            board[r][c] = '.';
        }
        
        // Put cell back (restore list)
        emptyCells.push_back({r, c});
        return false;
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        // Initialize masks and collect empties
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    emptyCells.emplace_back(r, c);
                } else {
                    int d = board[r][c] - '1';      // 0..8
                    int bit = 1 << d;
                    rows[r]  |= bit;
                    cols[c]  |= bit;
                    boxes[boxId(r,c)] |= bit;
                }
            }
        }
        dfs(board); // The problem guarantees exactly one solution. 
        
    }
};