class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        ////............. brute force............ ///////////
        //     for ( int i = 0; i < nums.size(); i++) {
        //         for (int j = i + 1; j < nums.size(); j++)
        //         {
        //             if (nums[i] == nums[j]) {
        //                 return true;
        //             }
        //         }
        //     }
        //     return false;
        // }

////////////.............hash table ........///////////////

        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (s.find(num) != s.end()) {
                return true;
            }
            s.insert(num);
        }
        return false;
    }
};