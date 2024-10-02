class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // declare a variabler
        int insertIndex = 1; // so first index will always have unique element
                             // which is 0 so will start from index 1
        for (int i = 1; i < nums.size(); i++) {
                // skip to next index if there is duplicate element 
            if (nums[i - 1] != nums[i]) {
                //store unique element at insertindex and increment insertindex by 1 to check other element. 
                nums[insertIndex] = nums[i];
                insertIndex++;
            }
        }
        return insertIndex;
    }
};