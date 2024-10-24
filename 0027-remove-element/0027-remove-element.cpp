class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;

        for (int i = 0; i < nums.size(); i++) {

            // if curent element is not equal to val

            if (nums[i] != val) {

                // move position to next valid element
                nums[j] = nums[i];
                
                j++;
            }
        }
        return j;
    }
    
};