class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        //  BRUTE FORCE APPROACH

        //     for (int i = 0; i < nums.size(); i++) {
        //         for (int j = i + 1; j < nums.size(); j++) {

        //             if (nums[i] + nums [j] == target) {
        //                 return {i, j};
        //             }
        //         }
        //     }
        //     return {};
        // }

        // ...........HASHING...........

        unordered_map<int, int> m;
        vector<int> result; // to store index

        for (int i = 0; i < nums.size(); i++) {
            int first = nums[i];
            int second = target - first;

            if (m.find(second) != m.end()) {  // search for second value in map 
                result.push_back(i);
                result.push_back(m[second]);

                break;
            }

            m[first] = i; // if not break then
        }
        return result;
    }
};