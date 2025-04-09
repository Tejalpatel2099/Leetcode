class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        long long low = 1, high = x, result = 0;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (mid * mid == x) {
                return mid;  // Found exact square root
            } else if (mid * mid < x) {
                result = mid;  // Update result to mid as it's the closest integer so far
                low = mid + 1;  // We need to check higher values
            } else {
                high = mid - 1;  // We need to check smaller values
            }
        }
        
        return result;
    }
};