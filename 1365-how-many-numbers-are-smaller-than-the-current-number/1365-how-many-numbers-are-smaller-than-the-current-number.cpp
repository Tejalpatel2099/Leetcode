class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    int n = nums.size();
        vector<int> ans(n, 0);

        // For each element, count how many are smaller than it
        for (int i = 0; i < n; i++) {
            int countSmaller = 0;

            for (int j = 0; j < n; j++) {
                if (i != j && nums[j] < nums[i]) {
                    countSmaller++;
                }
            }

            ans[i] = countSmaller;
        }

        return ans;
    }
};