class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int k = 0; 
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[k]) {
                k++; 
                nums[k] = nums[j]; 
            }
        }
        return k+1; 
    }
};