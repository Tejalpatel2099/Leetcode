
//  Brute Force Idea (Optional – shows thought process)
// "My first instinct is a brute force approach where for each element at index i, I compute the product of all elements except nums[i]. That would involve two nested loops, giving a time complexity of O(n²), which is inefficient for large arrays."

// \U0001f539 2. Optimized Approach – Prefix and Suffix Products
// _"To optimize this, I’ll use two auxiliary arrays: prefix and suffix.

// prefix[i] will store the product of all elements before index i.

// suffix[i] will store the product of all elements after index i.
// Finally, the result at index i will be prefix[i] * suffix[i]."_
//tc :- O(n) and SC:- O(n)  

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);

        // prefix
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        // suffix
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        // answer
        for (int i = 0; i < n; i++) {
            ans[i] = prefix[i] * suffix[i];
        }
        return ans;
    }
    
};