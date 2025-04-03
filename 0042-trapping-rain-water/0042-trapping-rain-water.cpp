class Solution {
public:



    int trap(vector<int>& height) {
//...................... TWO POINTER APPROACH..........................
    int ans = 0; 
    int n = height.size();
    int l = 0;
    int r = n - 1;
   
    int lmax = 0;
    int rmax = 0;

    while (l < r) {
        lmax = max(lmax,  height[l]);
        rmax = max(rmax, height[r]);

        if (lmax < rmax) {
            ans = ans + (lmax -height[l]);
            l++;
        } else {
            ans = ans + (rmax - height[r]);
            r--;
        }
    }
    return ans;
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
    
};