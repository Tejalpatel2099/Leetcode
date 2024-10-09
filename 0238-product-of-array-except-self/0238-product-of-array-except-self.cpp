class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1), right(n, 1), answer(n);
        // calculate left 
        for (int i = 1;  i < n; i++) {
            left[i] = left[i - 1] * nums[i - 1];
        }

        // Calculate right 
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i + 1];
        }

        // Calculate the answer by multiplying left and right 
        for (int i = 0; i < n; i++) {
            answer[i] = left[i] * right[i];
        }

        return answer;
    }
};