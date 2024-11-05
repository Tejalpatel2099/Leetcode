class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;  // Increment count for consecutive 1s
                if (count > maxCount) {
                    maxCount = count;  // Update  maxCount if cureent count is greater , if not greater than reset it to zero. 
                }
            } else {
                count = 0;  // Reset currentCount when it is 0 
            }
        }

        return maxCount;
    }
};