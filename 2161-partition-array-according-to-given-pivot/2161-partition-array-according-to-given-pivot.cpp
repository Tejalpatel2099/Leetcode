class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, equal, greater;
        
        // Classify elements into less, equal, and greater using a standard for loop
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot) {
                less.push_back(nums[i]);
            } else if (nums[i] == pivot) {
                equal.push_back(nums[i]);
            } else {
                greater.push_back(nums[i]);
            }
        }
        
        // Concatenate the three lists
        less.insert(less.end(), equal.begin(), equal.end());
        less.insert(less.end(), greater.begin(), greater.end());
        
        return less;
    }
};