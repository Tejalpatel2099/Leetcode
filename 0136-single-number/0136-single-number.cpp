class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            bool foundDuplicate = false;
            for (int j = 0; j < nums.size(); j++) {
                if (i != j && nums[i] == nums[j]) {
                    foundDuplicate = true;
                    break;
                }
            }
            if (!foundDuplicate) {
                return nums[i];
            }
        }
        return -1; // Should never reach here if input is valid
    }
};