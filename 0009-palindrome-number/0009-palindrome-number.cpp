// Can i assume that input is a 32-bit signed integer? Also, do we consider negative numbers as non-palindromes by definition? 
///The task is to check if the given number reads the same forwards and backwards. 
//...............brute force ...........
//One brute-force approach would be to convert the integer to a string, reverse it, and compare it to the original string. But that uses extra space for the string conversion
//Time Complexity: O(n) where n is number of digits
// Space Complexity: O(n) due to the string

// ......optimized ...........
//A more optimized solution is to reverse the number mathematically and compare it with the original. If both are equal, it's a palindrome.


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

// TC:- O(log n) 
// Sc  :- O(1) 

