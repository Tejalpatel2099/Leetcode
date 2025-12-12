class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();

        // count[i] will store how many times number i appears
        // this creates an array count of size n+1 
        vector<int> count(n + 1, 0); 

        //  count each number
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];   // current number
            count[x]++;        // increase its count
        }
// variables to store answers here , -1 is not found yet 
        int duplicate = -1;
        int missing = -1;

        //  find duplicate and missing number
        for (int i = 1; i <= n; i++) {
            if (count[i] == 2) {
                duplicate = i;   // number appears twice
            }
            if (count[i] == 0) {
                missing = i;     // number is missing
            }
        }

        //  return result
        return {duplicate, missing};
    }
};