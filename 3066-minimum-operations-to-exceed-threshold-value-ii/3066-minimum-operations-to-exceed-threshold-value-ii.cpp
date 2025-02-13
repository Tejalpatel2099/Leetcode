class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        priority_queue<long, vector<long>, greater<>> minHeap (nums.begin(), nums.end());
        int op = 0;
        
        while(minHeap.top() < k) {
            long a = minHeap.top(); minHeap.pop();
            long b = minHeap.top(); minHeap.pop();
            
            minHeap.push(min(a, b) * 2 + max(a, b));
            ++op;
        }
        
        return op;
    }
};