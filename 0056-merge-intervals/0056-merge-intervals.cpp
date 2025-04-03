class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return {}; // Handle edge case where intervals are empty

        sort(intervals.begin(), intervals.end()); // Sort by start time
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            if (ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]); // Add new interval
            } else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]); // Merge intervals
            }
        }

        return ans;
    }
};