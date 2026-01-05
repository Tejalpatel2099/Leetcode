class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expected = n * (n + 1) / 2;
        int actual = 0;

        for (int x : nums)  {
            actual = actual + x;
        }
        // for (int i = 0; i < n; i++) {
        //     actual = actual + nums[i];
        // } 
        return expected - actual;
    }
};