class Solution {
public:
    void getaperm(vector<int>& nums, int idx, vector<vector<int>>& ans) {
        if (idx  == nums.size()) {
            ans.push_back({nums});
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            getaperm(nums, idx + 1, ans);

            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getaperm(nums, 0, ans);
        return ans;
    }
};