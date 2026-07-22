class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);

        int maxlen = 0;

        for (int start = 0; start < n; start++) {
            if (visited[start]) {
                continue;
            }

            int curr = start;
            int cnt = 0;

            while (!visited[curr]) {
                visited[curr] = true;
                cnt++;

                curr = nums[curr];
            }

            maxlen = max(maxlen, cnt);
        }

        return maxlen;
    }
};