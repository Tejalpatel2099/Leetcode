class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freqMap;

        // Step 1: Count frequency of each word
        for (const string& word : words) {
            freqMap[word]++;
        }

        // Step 2: Define a min-heap with custom comparator
        auto cmp = [](pair<string, int>& a, pair<string, int>& b) {
            if (a.second == b.second)
                return a.first <
                       b.first;         // reverse lexicographical for min-heap
            return a.second > b.second; // min heap by frequency
        };

        priority_queue<pair<string, int>, vector<pair<string, int>>,
                       decltype(cmp)>
            minHeap(cmp);

        // Step 3: Push entries into heap, keeping only top k elements
        for (auto& entry : freqMap) {
            minHeap.push({entry.first, entry.second});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // Step 4: Extract from heap into result
        vector<string> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().first);
            minHeap.pop();
        }

        // Reverse the result to get highest freq first
        reverse(result.begin(), result.end());

        return result;
    }
};