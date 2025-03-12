class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0, neg = 0;
        
        // Iterate over the sorted array
        for (int num : nums) {
            if (num > 0) {
                pos++;  // Count positive integers
            } else if (num < 0) {
                neg++;  // Count negative integers
            }
        }
        
        // Return the maximum of positive and negative counts
        return max(pos, neg);
    }
};