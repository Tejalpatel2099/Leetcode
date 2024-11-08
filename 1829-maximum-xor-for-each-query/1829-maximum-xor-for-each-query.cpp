class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int k) {
        int x = (1L<<k)-1,y=0;
        for(auto &i: nums){
            y ^= i;
        }
        int a = y;
        for(int i = nums.size()-1; i>=0;i--){
            a = nums[i];
            nums[i]=(x^y);
            y ^= a;
        }
        reverse(nums.begin(),nums.end());
        return nums;
    }
};