class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        // Step 1: Sort the array to use two-pointer technique
        sort(nums.begin(), nums.end());

        // Step 2: Loop through each number, treating it as the first number of the triplet
        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicate values for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;              // Second pointer
            int k = nums.size() - 1;    // Third pointer

            // Step 3: Use two pointers to find valid triplets
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum < 0) {
                    // We need a larger number → move the left pointer right
                    j++;
                } else if (sum > 0) {
                    // We need a smaller number → move the right pointer left
                    k--;
                } else {
                    // Found a triplet
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    // Skip duplicates for second number
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }

                    // Skip duplicates for third number
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }
            }
        }

        return ans;
    }
};