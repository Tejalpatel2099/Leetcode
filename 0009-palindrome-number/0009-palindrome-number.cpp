// Can i assume that input is a 32-bit signed integer? Also, do we consider negative numbers as non-palindromes by definition? 
// What should I return for single-digit numbers?
///The task is to check if the given number reads the same forwards and backwards. 

//..............Brute force .....
// First, I considered the brute-force approach where I convert the number to a string, reverse it, and compare it with the original. This works, but it uses O(n) time and O(n) space, where n is the number of digits.
// ..........Optimized .............
// So to make to make the time complexity efficient I can think of is a optimized approach where I will be reversing the number mathematically and compare it with original and if both are equal it means that it's a palindrome.

// One thing I’m careful about is handling negative numbers — those are never palindromes by definition, so I return false immediately.

// I also used a long type for the reversed number to guard against integer overflow, even though it may not always be necessary if we're given a 32-bit int.”.

//The time complexity is O(log x) because I divide the number by 10 in each iteration, reducing the size logarithmically.
// Space Complexity: O(1) — only a few variables, no additional data structures used.


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


