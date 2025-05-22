class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //.........Kadane's algorithm ..........//
        int currSum = 0; 
        int maxSum = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            currSum = currSum + nums[i];
            maxSum = max(currSum, maxSum);

            if (currSum < 0) {
                currSum = 0; // reset value to zero 
            }
        }

        return maxSum;
    }
};
// tc :- O(n)
// sc:-  O(1)

    //...........bRute Force............//
    //     int maxSum = INT_MIN;

    //     for (int i = 0; i < nums.size() ; i++) {
    //         int currSum = 0;
    //         for (int j = i; j < nums.size(); j++) {
    //             currSum += nums[j];
    //             maxSum = max (currSum, maxSum);
    //         }
    //     } 
    //     return maxSum;
    // }
// tc :- O(n2) and Sc :- O(1)