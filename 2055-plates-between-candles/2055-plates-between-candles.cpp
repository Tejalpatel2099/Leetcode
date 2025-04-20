class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> prefixSum(n, 0); // plates count up to index i
        vector<int> leftCandle(n, -1);  // nearest candle to the left
        vector<int> rightCandle(n, -1); // nearest candle to the right

        // Build prefixSum
        int plates = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') plates++;
            prefixSum[i] = plates;
        }

        // Build leftCandle
        int lastCandle = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '|') lastCandle = i;
            leftCandle[i] = lastCandle;
        }

        // Build rightCandle
        lastCandle = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '|') lastCandle = i;
            rightCandle[i] = lastCandle;
        }

        // Answer the queries
        vector<int> result;
        for (auto& q : queries) {
            int left = q[0], right = q[1];
            int start = rightCandle[left];
            int end = leftCandle[right];

            if (start == -1 || end == -1 || start >= end) {
                result.push_back(0);
            } else {
                result.push_back(prefixSum[end] - prefixSum[start]);
            }
        }

        return result;
    }
};
