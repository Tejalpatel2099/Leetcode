class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int current = 0; 

        for (int i = 0; i < k; i++) {
            current = current + nums[i];
        }

        int max = current; 
        for ( int i = 1; i <= nums.size() - k; i++) {
            current = current - nums[i - 1] + nums[i + k - 1];
            if (current > max) {
                max = current;
            }
        }
        return static_cast<double>(max) / k;
    }
};