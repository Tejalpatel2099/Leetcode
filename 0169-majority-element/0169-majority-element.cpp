class Solution {
public:
    int majorityElement(vector<int>& nums) { // brute force
        int n = nums.size();
        for (int val : nums) { // intefger value in nums // value removed
            int freq = 0;

            for (int element : nums) {
                if (element == val) {
                    freq++;
                }
            }
            if (freq > n / 2) {
                return val;
            }
        }
        return -1;
    }
};