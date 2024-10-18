class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int a = nums[i];
            int more = target - a;

            if (mp.find(more) != mp.end()) {

                return {mp[more], i};
            }
            mp[a] = i;
        }
        return {-1, -1};
    }
};