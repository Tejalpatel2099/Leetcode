class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();           // number of rows
        int m = matrix[0].size();        // number of columns

        int low = 0, high = n * m - 1;   // virtual 1D array range

        while (low <= high) {
            int mid = low + (high - low) / 2;  // safer mid calculation
            int row = mid / m;                 // map to row index
            int col = mid % m;                 // map to column index

            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};


//................BRUTE FORCE ..........................//
//     for (int i = 0; i < row; i++) {
//         for (int j = 0; j < col; j++) {
//             if (matrix[i][j] == target) {
//                 return true;
//             }
//         }
//     }
//     return false;
// }