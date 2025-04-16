class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // Compare every pair of meetings
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int start1 = intervals[i][0];
                int end1 = intervals[i][1];
                int start2 = intervals[j][0];
                int end2 = intervals[j][1];

                // Check for overlap
                if (start1 < end2 && start2 < end1)
                    return false;
            }
        }
        return true;
    }
};
