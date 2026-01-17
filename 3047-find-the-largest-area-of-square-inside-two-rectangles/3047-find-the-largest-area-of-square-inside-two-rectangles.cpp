class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = (int)bottomLeft.size();
        long long best = 0;

        for (int i = 0; i < n; i++) {
            long long a1 = bottomLeft[i][0], b1 = bottomLeft[i][1];
            long long c1 = topRight[i][0],   d1 = topRight[i][1];

            for (int j = i + 1; j < n; j++) {
                long long a2 = bottomLeft[j][0], b2 = bottomLeft[j][1];
                long long c2 = topRight[j][0],   d2 = topRight[j][1];

                long long left   = max(a1, a2);
                long long right  = min(c1, c2);
                long long bottom = max(b1, b2);
                long long top    = min(d1, d2);

                long long w = right - left;
                long long h = top - bottom;

                if (w > 0 && h > 0) {
                    long long side = min(w, h);
                    best = max(best, side * side);
                }
            }
        }
        return best;
    }
};