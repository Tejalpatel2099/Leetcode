class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<long long> st(nums.begin(), nums.end());
        int maxcnt = -1;
        for (auto num : st) {
            int cnt = 0;
            while (st.find(num) != st.end()) {
                cnt++;
                num *= num;
            }

            if (cnt >= 2) {
                maxcnt = max(maxcnt, cnt);
            }
        }
        return maxcnt;
    }
};