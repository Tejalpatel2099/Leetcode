class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sumAbs = 0;           // sum of absolute values
        int negCount = 0;               // how many negatives
        long long minAbs = LLONG_MAX;   // smallest absolute value

        for (auto &row : matrix) {
            for (int x : row) {
                if (x < 0) negCount++;
                long long ax = llabs((long long)x); // abs value safely
                sumAbs += ax;
                minAbs = min(minAbs, ax);
            }
        }

        // If number of negatives is even, we can make everything positive
        if (negCount % 2 == 0) return sumAbs;

        // If odd, one value must remain negative -> subtract 2*minAbs
        return sumAbs - 2 * minAbs;
    }
};