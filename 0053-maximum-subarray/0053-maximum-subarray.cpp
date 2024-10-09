class Solution {
public:
    int maxSubArray(vector<int>& nums) {  // brute force approach 
        int maxSum = nums[0];
        int n = nums.size();
        
        for (int start = 0; start < n; start++) {
            int currentSum = 0;
            for (int end = start; end < n; end++) {
                currentSum = currentSum + nums[end];  // add end value in current sum 
                maxSum = max(maxSum, currentSum);
            }
        }
        
        return maxSum;
    }

};