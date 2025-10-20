//We need to find the largest group of numbers in the list such that their bitwise AND is greater than 0.
//That means — there exists at least one bit position (0–31) where all numbers in that group have the bit set to 1.
//So, the task reduces to finding —
//The maximum count of numbers that have a specific bit position set to 1.


class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        int ans = 0; // To store the largest combination size

        // Loop through all 32 bits (0 to 31)
        for (int i = 0; i < 32; i++) {
            int cnt = 0; // Count how many numbers have the i-th bit set

            // Check each candidate number
            for (auto candidate : candidates) {
                // If the i-th bit of candidate is set, increase the count
                if (candidate & (1 << i)) {
                    cnt++;
                }
            }

            // Update ans with the maximum count found so far
            ans = max(ans, cnt);
        }

        // Return the largest combination count
        return ans;
    }
};
//Time: O(n × 32) → each of the 32 bits is checked for all n numbers

// Space: O(1) → we only use a few variables