class Solution {
public:
    void sortColors(vector<int>& nums) {
        // sort(nums.begin(),nums.end());  // in built sort function O(log n)

        int n = nums.size();
        int count = 0;
        int count1 = 0;
        int count2 = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                count++;
            } else if (nums[i] == 1)
                count1++;
            else
                count2++;
        }
        int index = 0;

        for (int i = 0; i < count; i++) {
            nums[index++] = 0;
        }
        for (int i = 0; i < count1; i++) {
            nums[index++] = 1;
        }
        for (int i = 0; i < count2; i++) {
            nums[index++] = 2;
        }
    }
};