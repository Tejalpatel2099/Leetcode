class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0; // Handle edge case for empty array

        int i = 0; // Pointer for the position of unique elements
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++; // Move to the next position
                nums[i] =
                    nums[j]; // Update the array with the new unique element
            }
        }
        return i + 1; // Return the count of unique elements
    }
};