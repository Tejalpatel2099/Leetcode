class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size();

        // Step 1: Count occurrences of each element
        for (int i = 0; i < n; i++) {
            m[nums[i]]++;

            // Step 2: Check if the current element is the majority element
            if (m[nums[i]] > n / 2) {

                return nums[i];  // Return the majority element
            }
        }

        return -1;  
    }
};