
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();

        // Iterate through the array
        for (int i = 0; i < n; i++) {
            // Check if the current element is 0
            if (arr[i] == 0) {
                // Shift elements to the right, starting from the end
                for (int j = n - 1; j > i; j--) {
                    arr[j] = arr[j - 1];
                }
                // Place another 0 right after the current 0
                if (i + 1 < n) {
                    arr[i + 1] = 0;
                }
                // Skip the next position, as we just added a duplicated 0 there
                i++;
            }
        }
    }
};