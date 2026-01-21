class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        for (int a : nums) {
            if (a % 2 == 0) {
                res.push_back(-1);
            } else {
                res.push_back(a - ((a + 1) & (-a - 1)) / 2);
            }
        }
        return res;
    }
};