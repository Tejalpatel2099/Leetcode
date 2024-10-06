class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int n = nums.size(); // Get the size of the array
        for (int i = 0; i < n;
             ++i) { // outer loop to iterate through each element in array
            int val = nums[i];
            int freq = 0;

            for (int j = 0; j < n; ++j) { // inner loop
                if (nums[j] == val) {     // if found value
                    freq++;               // frequency increment
                }
            }
            if (freq > n / 2) { // if frequency is greater than n/2 then we
                                // found majority element.
                return val;
            }
        }
        return -1;
    }
};