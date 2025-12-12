// Brute force
// Create a set from the array (nums).
// Loop from 1 to n, and if a number is not in the set, add it to the result.
//

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        unordered_set<int> seen(nums.begin(), nums.end());
        vector<int> result;
        for (int i = 1; i <= nums.size(); ++i) {
            if (seen.find(i) == seen.end())
                result.push_back(i);
        }
        return result;
    }
};