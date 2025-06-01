// Questions 
// Are the intervals sorted or not ? 
// .....................BRUTE FORCE ...............
// idea is to Check every interval with all the rest and merge any overlapping ones using two loops. so first I will sort the intervals by their start time. and then use outer loop tpo pick each interval one by one. For each picked interval, use an inner loop to compare and merge it with the next intervals that overlap with it. If two intervals overlap, merge them by updating the end time.Skip any intervals that are already merged.Add the final merged interval to the result list.
// How to check overlap?--> If next interval's start <= current end, they overlap.
// TC :- O(n2)  and sc :- O(n) 

// Then I optimized it by first sorting the intervals by start time. After sorting, I only need to compare each interval with the last one in the result. If they overlap, I merge them. If not, I add it as a new interval. This reduces the time to O(n log n) due to sorting, and merging happens in one pass.
// Tc :- O(n log n) and sc :- O(n) Output list of merged interval. 

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        // Edge case: If no intervals are provided, return an empty list
        if (n == 0) return {};

        // Step 1: Sort intervals based on the starting time
        sort(intervals.begin(), intervals.end());

        // Initialize a vector to store the merged intervals
        vector<vector<int>> ans;

        // Step 2: Traverse through each interval
        for (int i = 0; i < n; i++) {
            // Case 1: If ans is empty or there is no overlap with the last interval in ans
            if (ans.empty() || intervals[i][0] > ans.back()[1]) {
                // Add the current interval to the result as a new interval
                ans.push_back(intervals[i]);
            } 
            // Case 2: There is an overlap with the last interval in ans
            else {
                // Merge the intervals by updating the end time to the max of both intervals' end times
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        // Return the list of merged intervals
        return ans;
    }
};