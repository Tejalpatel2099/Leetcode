// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         unordered_map<int,int>m;
//         for (int i = 0; i < nums.size(); i++) {
//             if (m.count(nums[i])) {
//                 m[nums[i]]++;
//             } else {
//                 m[nums[i]] = 1;
//             }
//         }
//         for (pair<int, int> p : m) {
//             if (p.second > nums.size() / 3) {
//                 cout << p.first;
//             }
//         }
//     }
// };
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        vector<int> result;

        // Count the frequency of each element
        for (int i = 0; i < nums.size(); i++) {
            if (m.count(nums[i])) {
                m[nums[i]]++;
            } else {
                m[nums[i]] = 1;
            }
        }

        // Find elements that appear more than n / 3 times
        for (const auto& p : m) {
            if (p.second > nums.size() / 3) {
                result.push_back(p.first);
            }
        }

        return result;
    }
};