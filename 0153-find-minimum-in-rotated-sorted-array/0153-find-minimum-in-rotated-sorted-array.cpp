class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        // Binary search
        while (left < right) {
            int mid = left + (right - left) / 2;

            // If middle element is greater than rightmost,
            // it means the minimum is in the right half
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                // Else, minimum is in the left half (including mid)
                right = mid;
            }
        }

        // At the end, left == right -> pointing to the minimum element
        return nums[left];
    }
};