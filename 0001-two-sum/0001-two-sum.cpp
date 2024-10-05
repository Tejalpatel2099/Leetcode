class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         vector<int> result; // Declare result vector to store indices
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) { 
                    result.push_back(i);  
                    result.push_back(j);
                    return result; // Return the result vector with indices
                }
            }
        }
        return result; // Return an empty vector if no solution found
    }
};
