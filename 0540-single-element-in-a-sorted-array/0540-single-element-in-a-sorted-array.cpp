class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        // If there's only one element, return it directly
        if (n == 1) 
        {
            return nums[0];
        }

        int st = 0, end = n - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            // Check if nums[mid] is the single non-duplicate
            
            if ((mid == 0 || nums[mid - 1] != nums[mid]) && 
                (mid == n - 1 || nums[mid + 1] != nums[mid])) {
                return nums[mid];
            }

            // If mid is even and the pair is not broken, move right
            if (mid % 2 == 0) {
                if (nums[mid] == nums[mid + 1]) {
                    st = mid + 2;
                } else {
                    end = mid - 1;
                }
            } else { // If mid is odd and the pair is not broken, move left
                if (nums[mid] == nums[mid - 1]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        // Default return, should never reach here
        return -1;
    }
};
