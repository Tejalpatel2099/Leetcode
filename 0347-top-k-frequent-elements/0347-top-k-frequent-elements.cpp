class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // count of frequency of each element 
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            freq[num] = freq[num] + 1;
        }

        priority_queue<pair<int,int>> pq;

        // Push all frequency pairs into the priority queue
        for (auto& pair : freq) {
         int number = pair.first;
        int frequency = pair.second;
        pq.push({frequency, number}); 
        }
        
        vector<int> result; 
        for (int i = 0; i < k; i++) {
            pair<int, int> top = pq.top(); // get top pair
            pq.pop();                      // remove it from heap
            result.push_back(top.second); // add the number (not frequency) to result
        }
        return result;
    }
};