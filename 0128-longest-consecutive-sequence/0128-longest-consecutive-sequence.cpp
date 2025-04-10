

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        int longest = 1;

        unordered_set<int> st;
        for(int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }
        

        for (auto it : st) {
            // Only check if it's the start of a sequence
            if (st.find(it - 1) == st.end()) {
                int count = 1;
                int x = it;

                while (st.find(x + 1) != st.end()) {
                    x = x + 1;
                    count = count + 1;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};
