// We are given an array of n non-negative integers representing an elevation map, where each element denotes the height of a bar. The width of each bar is 1. We need to compute how much water can be trapped between the bars after it rains.
// Questions ? 
// 1. Can the height values be very large or negative?
// 2. Are we guaranteed that the input is a valid array of non-negative integers?
// 3. Is the width of each bar always 1?
// 4. What should be the output if no water can be trapped? 
// 5.  Should I also return the positions where water is trapped or just the total amount?

// .............Brute force ...........
// Let me start with the brute-force approach to the Trapping Rain Water problem. The idea is to calculate how much water can be trapped on top of each bar by finding the tallest bar on the left and the tallest bar on the right for every index.
// where i will iterate over each bar and for each bar, find the max height to its left and find max height to its right from i to n -1. and water trapped on top of current bar is min(leftmax, rightmax) - height[i]. 
// Tc :- O(n2) and sc :- O(1) 

// .....................TWO POINTER APPROACH ................
// To optimize it, I used the two-pointer technique. Instead of checking all elements to the left and right every time, I maintain two pointers—left and right—starting at both ends of the array. I also track the current leftMax and rightMax as we move inward. 
// Water trapped at any bar depends on the shorter of the tallest bars to its left and right.
// we move the pointer that has the smaller height and update the corresponding leftMax or rightMax.
// tc :- O(n) and sc:- O(1) 

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;                // Stores the total amount of trapped water
        int n = height.size();      // Size of the input array
        int l = 0;                  // Left pointer starting from the beginning
        int r = n - 1;              // Right pointer starting from the end

        int lmax = 0;               // Tracks the maximum height seen so far from the left
        int rmax = 0;               // Tracks the maximum height seen so far from the right

        // Continue the loop until both pointers meet
        while (l < r) {
            // Update the maximums seen from both ends
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);

            // The key insight: water is trapped based on the smaller of the two max heights
            if (lmax < rmax) {
                // Since lmax is smaller, it is the limiting factor on the left
                // Water trapped at this point = lmax - current height (if lmax > height[l])
                ans += (lmax - height[l]);
                l++; // Move left pointer to the right
            } else {
                // rmax is smaller or equal, so it is the limiting factor on the right
                // Water trapped at this point = rmax - current height (if rmax > height[r])
                ans += (rmax - height[r]);
                r--; // Move right pointer to the left
            }
        }

        return ans; // Return the total trapped water
    }
};

 // ......... brute force .............................
//         int n = height.size();
//     int trappedWater = 0;
             
//     for (int i = 0; i < n; ++i) {
//         int leftMax = 0;
//         for (int j = 0; j <= i; ++j) {
//             leftMax = max(leftMax, height[j]);
//         }

//         int rightMax = 0;
//         for (int j = i; j < n; ++j) {
//             rightMax = max(rightMax, height[j]);
//         }

//         trappedWater = trappedWater +  max(0, min(leftMax, rightMax) - height[i]);
//     }

//     return trappedWater;
// }
    