class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        // approach max heap 
    //     priority_queue<int> pq;

    //     for (int i = 0; i < nums.size(); i++) {
    //         pq.push(nums[i]);
    //     }

    //     int ans = 0;
    //     while (k > 0) {
    //         ans = pq.top();
    //         pq.pop();
    //         k--;
    //     }

    //     return ans;
    // }

    // apprioach for min heap 

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);

            if (pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top();
    }
};