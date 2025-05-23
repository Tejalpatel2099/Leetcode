class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for ( int i = 0; i < nums.size(); i++) {
          if (s.find(nums[i]) != s.end()) {
            return true; // duplicate found
          }
           s.insert(nums[i]);
        }
        return false; // no duplicate found 
    }
};

// ........Brute force approach 
// bool containsDuplicate(vector<int>& nums) {
// for ( int i = 0; i < nums.size(); i++) {
    // for (int j = i + 1; j < nums.size(); j++) {
        // if(nums[i] == nums[j]) 
        //return true;
    //}
//}
//return false;
// tc  :- o(n2) sc :- O(1)