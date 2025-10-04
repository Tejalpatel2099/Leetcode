// I use a prefix–suffix product approach.
// I multiply elements from both ends, resetting whenever I hit a zero, and keep track of the maximum product seen.
// This single pass automatically handles positives, negatives, and zeros—giving the maximum product subarray efficiently in O(n) time


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(); // size of array.

        int pre = 1, suff = 1;
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (pre == 0)
                pre = 1;
            if (suff == 0)
                suff = 1;
            pre *= nums[i];
            suff *= nums[n - i - 1];
            ans = max(ans, max(pre, suff));
        }
        return ans;
    }
};

// Case 1:
// If all numbers are positive, multiplying them all gives the maximum product.
// → Entire array is the answer.

// Case 2:
// If there are even negatives, their product becomes positive.
// → Again, entire array gives the max product.

// Case 3:
// If there are odd negatives, one of them must be removed (since removing one negative makes the count even → product positive).
// → The max product will be from either:

// the subarray before the first negative, or

// the subarray after the last negative.

// Case 4:
// If there are zeros, they act as separators (since any product including 0 becomes 0).
// → Split the array at 0s, solve for each non-zero part using Case 3 logic, and take the overall max.


