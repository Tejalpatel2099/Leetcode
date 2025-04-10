class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        vector<int>prefixSum(n, 0);
        prefixSum[0]= nums[0];

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i]; // to claculate prefix sum 
        }

        // to claculate count 
        unordered_map<int, int> m;
        for (int j = 0; j < n; j++) {
            if (prefixSum[j] == k) {
                count++;
            }
            int val = prefixSum[j] - k;
            if (m.find(val) != m.end()) {
                count = count + m[val];
            }
            // if ps is alraedy in map then do freq++

            if (m.find(prefixSum[j]) == m.end()) {
                m[prefixSum[j]] = 0;
            }
            m[prefixSum[j]]++;
        }
        return count;
    }
};