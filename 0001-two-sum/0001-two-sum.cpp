// I can check all pairs of elements in the array to see which two sum up to the target. This means I'll use two nested loops—one for the first number and the other for the second. Since I’m checking every pair, the time complexity is quadratic.O(n^2) and "I’m not using any extra space apart from the output O(1).

// optimized appraoch 
//To improve efficiency, I’ll use a hash map to store each number as I iterate, mapping the number to its index. For each number, I calculate the complement (target - number), and if that complement is already in the map, I return the indices.We iterate through the array once and each lookup in the hash map is constant time Tc O(n)and SC is O(n).



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