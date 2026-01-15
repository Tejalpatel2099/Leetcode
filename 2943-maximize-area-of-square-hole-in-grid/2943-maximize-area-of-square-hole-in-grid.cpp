class Solution {
public:
    int longestConsecutiveRun(vector<int>& bars) {
        if (bars.empty()) return 0;

        sort(bars.begin(), bars.end());

        int best = 1, cur = 1;
        for (int i = 1; i < (int)bars.size(); i++) {
            if (bars[i] == bars[i - 1] + 1) {
                cur++;
            } else {
                cur = 1;
            }
            best = max(best, cur);
        }
        return best; // number of consecutive removed bars
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxHrun = longestConsecutiveRun(hBars); // longest streak in horizontal removals
        int maxVrun = longestConsecutiveRun(vBars); // longest streak in vertical removals

        int height = maxHrun + 1; // hole size in that direction
        int width  = maxVrun + 1;

        int side = min(height, width);
        return side * side;
        
    }
};