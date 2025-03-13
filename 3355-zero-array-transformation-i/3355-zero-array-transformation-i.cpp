class Solution {
public:
    // Function that determines if an array can be turned into a zero array 
    // using the given range increment queries.
    bool isZeroArray(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        int n = nums.size();
        int differenceArray[n + 1]; // Initialize a difference array of size n + 1
        std::memset(differenceArray, 0, sizeof(differenceArray)); // Set all elements to 0

        // Apply the range increment operations using the difference array technique
        for (const auto& query : queries) {
            int left = query[0], right = query[1];
            ++differenceArray[left];
            --differenceArray[right + 1]; // Decrement at right + 1 to end the increment effect
        }

        // Check if the array after applying all queries can be turned into a zero array
        int currentSum = 0;
        for (int i = 0; i < n; ++i) {
            currentSum += differenceArray[i];
            if (nums[i] > currentSum) {
                return false; // Return false if currentSum is less than nums[i]
            }
        }
        return true; // Return true if all conditions are satisfied
    }
};