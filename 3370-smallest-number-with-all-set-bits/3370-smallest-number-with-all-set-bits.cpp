class Solution {
public:
    int smallestNumber(int n) {
        long long x = 1; // start with binary '1'
        while (x < n) {
            x = (x << 1) | 1; // shift left and set next bit to 1
        }
        return (int)x;
    }
};