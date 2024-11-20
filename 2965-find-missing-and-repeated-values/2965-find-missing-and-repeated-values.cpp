class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;

        unordered_set<int> s;
        int n = grid.size();
        int a = -1, b = -1;
        int expSum = 0;
        int actualSum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                actualSum += grid[i][j];

                if (s.find(grid[i][j]) != s.end()) {
                    a = grid[i][j]; // Repeated number
                }
                s.insert(grid[i][j]);
            }
        }

        // Calculate the expected sum
        expSum = (n * n) * (n * n + 1) / 2;
        
        // Calculate the missing number
        b = expSum + a - actualSum;

        // Add results to the answer
        ans.push_back(a); // Repeated
        ans.push_back(b); // Missing

        return ans;
    }
};
