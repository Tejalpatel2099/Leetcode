// clarifying questions
// 1 . are single characters considered palindromes? 
//2 . Do we need to return the count or list of palindromic substrings?
// 3. Are the input strings limited in length? 

//Instead of checking every possible substring, I try to expand around every possible center to count palindromes.For a string of length n, there are 2n - 1 possible centers:n for odd-length palindromes (centered on a character)n - 1 for even-length palindromes (centered between two characters)  for each center, I expand outward (left and right) as long as characters match (s[left] == s[right]), and count those as palindromic substrings. 

// tc :- O(n2) and sc:- O(1)

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;              // Initialize the counter for palindromic substrings
        int n = s.length();         // Get the length of the string

        // Loop over all possible centers (2n - 1 total)
        for (int center = 0; center < 2 * n - 1; ++center) {

            int left = center / 2;                  // Compute the left index of the current center
            int right = left + (center % 2);        // Compute the right index (same as left for odd length, +1 for even)

            // Expand around the center as long as characters match
            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;         // Found a palindromic substring
                left--;          // Move left pointer one step left
                right++;         // Move right pointer one step right
            }
        }

        return count;  // Return total count of palindromic substrings
    }
};
