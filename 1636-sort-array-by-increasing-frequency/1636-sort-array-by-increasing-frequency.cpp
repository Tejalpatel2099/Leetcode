class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
         unordered_map<int, int> freq;

        // Step 1: Count frequency of each number
        for (int n : nums) {
            freq[n]++;
        }

        // Step 2: Sort using custom comparator
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (freq[a] == freq[b])
                return a > b;  // Same frequency → sort by decreasing value
            return freq[a] < freq[b];  // Otherwise → sort by increasing frequency
        });

        return nums;
    }
};