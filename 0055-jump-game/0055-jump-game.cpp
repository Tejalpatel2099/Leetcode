class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = nums[0];

        for (int i = 0; i < nums.size() - 1; i++) {
            if (maxIndex >= nums.size() -1) {
                return true;
            }
            if (nums[i] == 0 && maxIndex == i) {
                return false;
            }
            if (i + nums[i] > maxIndex) {
                maxIndex = i + nums[i];
            }
        }
        return true;
    }
};


