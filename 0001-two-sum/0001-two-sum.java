class Solution {
    public int[] twoSum(int[] nums, int target)
     {
        // HashMap to store value -> index
        Map<Integer, Integer> map = new HashMap<>();
        
        for (int i = 0; i < nums.length; i++) {
            int first = nums[i];
            int second = target - first;
            
            // If complement exists in map
            if (map.containsKey(second)) {
                return new int[]{map.get(second), i};
            }
            
            // Store current number with index
            map.put(first, i);
        }
        
        // If no solution found (though problem guarantees one)
        return new int[]{};


        //................... JAVA Brute force ...................
    //    for (int i = 0; i < nums.length; i++) {
    //         for (int j = i + 1; j < nums.length; j++) { // j starts from i+1 (avoid duplicates)
    //             if (nums[i] + nums[j] == target) {
    //                 return new int[]{i, j};
    //             }
    //         }
    //     }
    //     return new int[]{}; 
    }
}

// ..........................C++ ...................................
// class Solution { 
//     public: 
//     vector<int> twoSum(vector<int>& nums, int target) { 
//         unordered_map<int, int> m; 
//         for (int i = 0; i < nums.size(); i++) { 
//             int first = nums[i]; 
//             int second = target - first; 
//             if (m.find(second) != m.end()) { 
//                 return {m[second], i}; // Return indices of the two numbers } m[first] = i; // Store the index of the current number } return {}; // Return empty if no solution found } }; 
//                 // .............brute force ........................... 
//                 // for(int i = 0; i < nums.size(); i++) { 
//                     // for(int j = 0; j < nums.size(); j++) { 
//                         // if (nums[i] + nums[j] == target) { 
//                             // return {i, j}; 
//                             // } 
//                             // } 
//                             // } 
//                             // return {}; 
//                             // } 
//                             // };