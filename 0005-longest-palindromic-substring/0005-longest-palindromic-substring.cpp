// o confirm, we are given a string s and we need to return the longest substring that is a palindrome — meaning it reads the same forwards and backwards. Is there any specific constraint on the string length?

// A brute-force approach would be to generate all possible substrings and check each one to see if it’s a palindrome. Loop over all possible starting and ending indices. Check if the substring between those indices is a palindrome.

// tc:- O(n3)and sc:- O(1)

//To find the longest palindromic substring, we go through each character in the string and try to expand around it to check how far the palindrome stretches. We do this twice for each character—once treating it as the center for odd-length palindromes (like "racecar") and once treating the gap between it and the next character as the center for even-length palindromes (like "abba"). A helper function keeps expanding outward as long as the characters on both sides match, returning the length of the palindrome. We update our longest found substring whenever we discover a longer one by adjusting the start and end indices. Finally, we return the longest palindrome using those indices. This approach ensures we check all possible centers efficiently.


class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";  // Edge case: empty string has no palindrome
        }

        int start = 0, end = 0; // Will hold start and end indices of the longest palindrome

        // Loop through each character in the string
        for (int i = 0; i < s.length(); i++) {
            // Check for odd-length palindrome centered at s[i]
            int odd = expandAroundCenter(s, i, i);

            // Check for even-length palindrome centered between s[i] and s[i+1]
            int even = expandAroundCenter(s, i, i + 1);

            // Take the longer length
            int max_len = max(odd, even);

            // Update start and end if this palindrome is longer than the previous longest
            if (max_len > end - start) {
                // Compute the new start and end based on the center and length
                start = i - (max_len - 1) / 2;
                end = i + max_len / 2;
            }
        }

        // Return the longest palindromic substring
        return s.substr(start, end - start + 1);        
    }

private:
    // Helper function to expand the palindrome around the center
    int expandAroundCenter(string s, int left, int right) {
        // Expand as long as the characters match and indices are in bounds
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }

        // Return the length of the palindrome found
        return right - left - 1; // Subtract 1 because we've expanded one step too far
    }    
};

// tc :- O(n2) and sc :- O(1) 
 