
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> mpp;

        for (auto i : nums) {
            mpp[i]++;
        }

        for (auto i : mpp) {
            int key = i.first;
            int val = i.second;
            pq.push(make_pair(val, key));
        }

        vector<int> ans;
        while (k > 0) {
            if (!pq.empty()) {
                pair<int, int> i = pq.top();
                ans.push_back(i.second);
                pq.pop();
            }
            k--;
        }
        return ans;
    }
};

// unordered_map<int, int> freqMap;

// // Step 1: Count frequency of each number
// for (int num : nums) {
//     freqMap[num]++;
// }

// // Step 2: Create buckets. Index = frequency, Value = list of numbers
// int n = nums.size();
// vector<vector<int>> buckets(n + 1); // because max frequency can be n

// for (auto& pair : freqMap) {
//     int number = pair.first;
//     int frequency = pair.second;
//     buckets[frequency].push_back(number);
// }

// // Step 3: Collect k most frequent elements from the end
// vector<int> result;
// for (int i = n; i >= 0 && result.size() < k; --i) {
//     for (int num : buckets[i]) {
//         result.push_back(num);
//         if (result.size() == k) {
//             break;
//         }
//     }
// }

// return result;