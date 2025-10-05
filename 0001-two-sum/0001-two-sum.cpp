class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        
        for (int i = 0; i < nums.size(); i++) {
            int first = nums[i];
            int second = target - first;

            if (m.find(second) != m.end()) {
                return {m[second], i}; // Return indices of the two numbers
            }

            m[first] = i; // Store the index of the current number
        }

        return {}; // Return empty if no solution found
    }
};
 
 // .............brute force ...........................
//        for(int i = 0; i < nums.size(); i++) {
//            for(int j = 0; j < nums.size(); j++) {
//                if (nums[i] + nums[j] == target) {
//                    return {i, j};
//                }
//            }
           
//        }
//         return {};
//     }
// };