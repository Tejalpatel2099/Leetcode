
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = (int)matrix.size();
        int cols = (int)matrix[0].size();

        vector<int> heights(cols, 0);
        int best = 0;

        for (int r = 0; r < rows; r++) {
            // Build histogram heights for this row
            for (int c = 0; c < cols; c++) {
                if (matrix[r][c] == '1') heights[c] += 1;
                else heights[c] = 0;
            }

            // Largest rectangle in histogram (heights)
            best = max(best, largestHistogramArea(heights));
        }

        return best;
    }

private:
    int largestHistogramArea(const vector<int>& h) {
        int n = (int)h.size();
        stack<int> st;              // stores indices with increasing heights
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n) ? 0 : h[i]; // sentinel 0 to flush stack

            while (!st.empty() && h[st.top()] > currHeight) {
                int height = h[st.top()];
                st.pop();

                int right = i;                      // first index to the right that is smaller
                int left = st.empty() ? -1 : st.top(); // index of previous smaller
                int width = right - left - 1;

                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        return maxArea;
    }
};
