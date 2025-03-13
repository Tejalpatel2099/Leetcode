

class Solution {
public:
    bool isZeroArray(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        int n = nums.size();
        std::vector<int> differenceArray(n + 1, 0); // Create a difference array with initial values of 0

        // Apply the range increment operations using the difference array
        for (int i = 0; i < queries.size(); ++i) {
            int left = queries[i][0], right = queries[i][1];
            differenceArray[left]++;    // Increment at the left index
            if (right + 1 < n) {
                differenceArray[right + 1]--; // Decrement at right + 1 (if within bounds)
            }
        }

        // Check if we can turn the array into a zero array after applying the queries
        int currentSum = 0;
        for (int i = 0; i < n; ++i) {
            currentSum += differenceArray[i]; // Add to the current sum
            if (nums[i] > currentSum) {
                return false; // If nums[i] is greater than the current sum, return false
            }
        }
        return true; // If all checks pass, return true
    }
};
