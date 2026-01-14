

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int val = 1;

        while (top <= bottom && left <= right) {
            // 1) left -> right (top row)
            for (int j = left; j <= right; j++) mat[top][j] = val++;
            top++;

            // 2) top -> bottom (right col)
            for (int i = top; i <= bottom; i++) mat[i][right] = val++;
            right--;

            // 3) right -> left (bottom row) if still valid
            if (top <= bottom) {
                for (int j = right; j >= left; j--) mat[bottom][j] = val++;
                bottom--;
            }

            // 4) bottom -> top (left col) if still valid
            if (left <= right) {
                for (int i = bottom; i >= top; i--) mat[i][left] = val++;
                left++;
            }
        }

        return mat;
    }
};
