// Can x be any integer (positive/negative/zero)?
// Do we need to return the subarray, or just the frequency?
//  Can we perform the operation more than once?

// ..........Brute force .......
//  i will try every possible sub array and try to find that when added to the
//  subarray makes some values becomes k and then i will count how many elements
//  become k after adding x.  but the TC  :- O(n3) and sc:- O(1)

// The solution is built on a variation of the Maximum Subarray Sum (Kadane’s
// Algorithm). For each potential value m ≠ k, we try to find the longest
// subarray we can convert to k by adding (k - m). But instead of actually
// changing values, we simulate it using a counting trick

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // Count how many times k already appears in the array
        int orig = count(nums.begin(), nums.end(), k);

        int maxGain = 0; // To track maximum number of additional k's we can get

        // Try every number m from 1 to 50 (based on input constraint)
        for (int m = 1; m <= 50; ++m) {
            if (m == k)
                continue; // Skip if m is already k

            int currentGain = 0;    // Gain in current subarray
            int maxCurrentGain = 0; // Max gain for current m

            for (int n : nums) {
                // If current number is m, we can potentially convert it to k
                if (n == m) {
                    currentGain += 1;
                }
                // If current number is already k, we risk losing it if it's in
                // subarray
                else if (n == k) {
                    currentGain -= 1;
                }
                // Else: number is neither m nor k, ignore it (treat as 0)

                // Reset gain if it drops below 0 (Kadane’s trick)
                if (currentGain < 0) {
                    currentGain = 0;
                }

                // Track the max gain so far for
                maxCurrentGain = max(maxCurrentGain, currentGain);
            }

            // Update overall max gain across all m values
            maxGain = max(maxGain, maxCurrentGain);
        }

        // Final answer = already existing k's + max gain from one subarray
        // conversion
        return orig + maxGain;
    }
};