class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> s(nums.begin(), nums.end());
        int temp = k;
        while (s.find(temp) != s.end()) {
            temp = temp + k;
        }
        return temp;
    }
};