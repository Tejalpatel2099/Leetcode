class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Condition 1: If n is 1, it's a power of two
        if (n == 1) {
            return true;
        }

        // Condition 2: If n is less than or equal to 0, it's not a power of two
        if (n <= 0) {
            return false;
        }

        // Condition 3: If n is greater than 0, check if it can be divided by 2 repeatedly
        while (n % 2 == 0) {
            n = n / 2;  // Divide n by 2
        }

        // If n is 1 after division, it's a power of two
        return n == 1;
    }
};
