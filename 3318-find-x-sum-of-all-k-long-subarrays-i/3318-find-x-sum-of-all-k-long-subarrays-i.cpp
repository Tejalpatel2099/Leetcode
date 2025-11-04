class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        const int MAX_VAL = 50;  // because 1 <= nums[i] <= 50
        
        vector<int> freq(MAX_VAL + 1, 0);  // freq[value]
        vector<int> answer;

        // Helper lambda to compute x-sum from current freq array
        auto computeXSum = [&](const vector<int>& freq) -> int {
            // Collect (value, count) pairs for values that appear
            vector<pair<int, int>> elems; // {value, count}
            for (int val = 1; val <= MAX_VAL; ++val) {
                if (freq[val] > 0) {
                    elems.push_back({val, freq[val]});
                }
            }

            // Sort: first by count descending, then by value descending
            sort(elems.begin(), elems.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
                if (a.second != b.second) {
                    return a.second > b.second;  // more frequent first
                }
                return a.first > b.first;        // bigger value first if tie
            });

            int take = min(x, (int)elems.size());
            long long sum = 0;

            // Sum value * count for the top x elements
            for (int i = 0; i < take; ++i) {
                sum += 1LL * elems[i].first * elems[i].second;
            }

            return (int)sum;
        };

        // Initialize frequency for the first window [0 .. k-1]
        for (int i = 0; i < k; ++i) {
            freq[nums[i]]++;
        }

        // Compute x-sum for the first window
        answer.push_back(computeXSum(freq));

        // Slide the window over the rest of the array
        for (int i = k; i < n; ++i) {
            // Window moves from [i-k .. i-1] to [i-k+1 .. i]
            freq[nums[i - k]]--;  // remove element leaving the window
            freq[nums[i]]++;      // add new element entering the window

            answer.push_back(computeXSum(freq));
        }

        return answer;
    }
};