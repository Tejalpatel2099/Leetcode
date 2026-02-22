class Solution {
public:
    // Count how many numbers <= mid in O(n)
    int countLessEqual(const vector<vector<int>>& matrix, int mid) {
        int n = matrix.size();
        int row = n - 1;   // start bottom-left
        int col = 0;
        int count = 0;

        while (row >= 0 && col < n) {
            if (matrix[row][col] <= mid) {
                // all elements in this column from 0..row are <= mid
                count += (row + 1);
                col++; // move right
            } else {
                row--; // move up
            }
        }
        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];

        while (low < high) {
            int mid = low + (high - low) / 2;
            int cnt = countLessEqual(matrix, mid);

            if (cnt < k) low = mid + 1;  // need bigger numbers
            else high = mid;             // mid might be answer
        }
        return low;
    }
};