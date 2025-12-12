class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();

        // count[i] will store how many times number i appears
        vector<int> count(n + 1, 0);

        // STEP 1: count each number
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];   // current number
            count[x]++;        // increase its count
        }

        int duplicate = -1;
        int missing = -1;

        // STEP 2: find duplicate and missing number
        for (int i = 1; i <= n; i++) {
            if (count[i] == 2) {
                duplicate = i;   // number appears twice
            }
            if (count[i] == 0) {
                missing = i;     // number is missing
            }
        }

        // STEP 3: return result
        return {duplicate, missing};
    }
};