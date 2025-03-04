class Solution {
public:
    bool checkPowersOfThree(int n) {
           while (n > 0) {
            // If n is divisible by 3, we can subtract a power of 3 from it.
            if (n % 3 == 2) {
                return false;  // If remainder is 2, it's impossible to represent n as distinct powers of 3
            }
            n /= 3;  // Divide by 3 to check the next digit in base 3
        }
        return true;  // If we can completely reduce n to 0, return true
    }
};