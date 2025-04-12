class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
    
private:
    int binarySearch(vector<int>& nums, int start, int end, int target) {
        if (start > end) {
            return -1;
        }
        
        int mid = start + (end - start) / 2;
        
        if (nums[mid] == target) {
            return mid;
        }
        
        // Check if the left half is sorted
        if (nums[start] <= nums[mid]) {
            // Target is in the left half
            if (nums[start] <= target && target <= nums[mid]) {
                return binarySearch(nums, start, mid - 1, target);
            } else {
                // Target is in the right half
                return binarySearch(nums, mid + 1, end, target);
            }
        } else { // Right half is sorted
            // Target is in the right half
            if (nums[mid] <= target && target <= nums[end]) {
                return binarySearch(nums, mid + 1, end, target);
            } else {
                // Target is in the left half
                return binarySearch(nums, start, mid - 1, target);
            }
        }
    }
};