class Solution {
private:
    void transpose(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i; j < matrix[0].size(); ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }

    void reverseRows(vector<vector<int>>& matrix) {
        for (int r = 0; r < matrix.size(); ++r) {
            int left = 0;
            int right = matrix.size() - 1;

            while (left < right) {
                int temp = matrix[r][left];
                matrix[r][left] = matrix[r][right];
                matrix[r][right] = temp;

                ++left;
                --right;
            }
        }
    }

public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverseRows(matrix);
    }
};