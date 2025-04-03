class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        
        // If k is 1, then the entire array is one bag, so there's only one cost.
        if (k == 1) return 0;

        vector<long long> cost;  // Store pairwise sums of adjacent elements
        int n = weights.size();
        
        // Step 1: Calculate pairwise sums of adjacent marbles
        for (int i = 0; i < n - 1; i++) {
            cost.push_back(weights[i] + weights[i + 1]);
        }

        // Step 2: Sort the cost array
        sort(cost.begin(), cost.end());

        // Step 3: For max score, pick k-1 largest gaps (highest k-1 sums)
        long long maxScore = 0;
        for (int i = n - 2; i >= n - k; i--) {
            maxScore += cost[i];
        }

        // Step 4: For min score, pick k-1 smallest gaps (lowest k-1 sums)
        long long minScore = 0;
        for (int i = 0; i < k - 1; i++) {
            minScore += cost[i];
        }

        // Step 5: Return the difference
        return maxScore - minScore;
    }
};