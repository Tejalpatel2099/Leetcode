// "To solve this problem, I'll first walk through a brute force approach, then explain its limitations, and finally present an optimized solution using dynamic programming."

// \U0001f9e0 Step-by-Step Interview Flow
// \U0001f539 1. State the Problem
// "We are given an array of integers, and we need to find the length of the longest increasing subsequence (LIS). A subsequence is not required to be contiguous, but it should be in increasing order."

// \U0001f539 2. Brute Force Idea (Optional but shows depth)
// "The brute-force approach would involve generating all possible subsequences, checking which ones are strictly increasing, and returning the length of the longest one. However, this has exponential time complexity — O(2ⁿ) — making it inefficient for large inputs."

// \U0001f539 3. Optimized Approach (Dynamic Programming)
// "To improve on this, I’ll use dynamic programming. I’ll create a dp array where each dp[i] stores the length of the longest increasing subsequence ending at index i."

// "For each element at index i, I compare it with all previous elements j < i. If nums[i] > nums[j], then nums[i] can extend the subsequence ending at j. So I update dp[i] = max(dp[i], dp[j] + 1)."

// "Finally, I return the maximum value in the dp array, which represents the length of the LIS."


class Solution { // 256 ms, faster than 42.84%
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
        return *max_element(dp.begin(), dp.end());
    }
};