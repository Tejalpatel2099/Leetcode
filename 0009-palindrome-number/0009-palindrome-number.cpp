class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false; // Negative numbers are not palindromes
        }

        int original = x; // Store the original number
        long reverse = 0; // Use long to handle overflow

        while (x > 0) {
            int digit = x % 10;      // Extract the last digit
            reverse = reverse * 10 + digit; // Build the reversed number
            x = x / 10;             // Remove the last digit
        }

        // Compare the original number with the reversed number
        return original == reverse;
    }
};
