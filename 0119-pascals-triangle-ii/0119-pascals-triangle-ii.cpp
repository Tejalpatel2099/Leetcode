class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1); // Initialize all elements to 1
        for (int i = 1; i < rowIndex; ++i) {
            // Update from the end to the beginning to avoid overwriting
            // previous values
            for (int j = i; j > 0; --j) {
                row[j] += row[j - 1];
            }
        }
        return row;
    }
};