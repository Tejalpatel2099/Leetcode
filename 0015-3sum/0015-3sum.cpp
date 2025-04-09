class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        set<vector<int>>s;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int>triplet = {nums[i], nums[j] , nums[k] };
                        sort(triplet.begin(), triplet.end());

                        if (s.find(triplet) == s.end()) {
                            s.insert(triplet);
                            result.push_back(triplet);
                        }
                    }
                }
            }
        }
        return result;
    }
};