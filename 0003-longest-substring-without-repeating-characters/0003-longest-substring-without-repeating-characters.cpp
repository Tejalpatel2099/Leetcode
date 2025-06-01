// Start with a Brute-Force Approach
//  “I’d like to start with a brute-force solution

// “In the brute-force version, I can try every possible substring using two
// nested loops. For each substring, I check whether it contains all unique
// characters by inserting them into a set.”

// Logic:

// Outer loop from index i = 0 to n-1

// Inner loop from j = i to n-1

// Use a set to track unique characters

// If a character repeats, break and compare length

// “This gives us a time complexity of O(n³) — O(n²) for substrings and O(n) to
// check uniqueness. It’s correct but too slow for large inputs.”

//  3. Transition to Optimized Approach
// “To improve this, I’ll use a sliding window approach with a hash set or map
// to avoid rechecking characters.”

// “The idea is to maintain a window [left, right] that always contains unique
// characters only. I slide the right pointer to expand the window, and if I
// find a repeating character, I shrink the window from the left.”

// “To make it even more efficient, I’ll store the last seen index of each
// character in a hash map or a vector of size 256 (ASCII). This way, I can jump
// the left pointer directly to the right of the last occurrence.”

// ✅ 4. Code Explanation (during or after coding)
// “I initialize a vector lastIndex(256, -1) to keep the last position of each
// character.”

// “While moving right, if the current character was seen after left, I move
// left to lastIndex[s[right]] + 1.”

// “I then update the character’s latest index and calculate the window size:
// right - left + 1, updating the max length.”

// ✅ 5. Time & Space Complexity
// Time Complexity: O(n) – each character is visited once.

// Space Complexity: O(1) – for ASCII character set (constant size vector).

// “This is optimal for this problem and performs well even on large strings.”
//

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // craete a vecxtor of size 256 and all values are initialkized
        // to -1 means this character has not been seen yet . and it
        // will store last index  of each character in the string .
        vector<int> map(256, -1);
        int left = 0, right = 0; // left and right are two pointers used to
                                 // define the sliding window of current substr
        int n = s.size();
        int len = 0;        // stores length of the string
        while (right < n) { // loop through string using right pointer
            if (map[s[right]] !=
                -1) // if current character s[right] was seen before and it is
                    // still inside the current windoe(left, right) then
                left = max(map[s[right]] + 1,
                           left); // i will move left pointer to one position
                                  // after the last index of that character

            map[s[right]] = right; // updater the last seen index of s[right] to
                                   // the current psotion right

            len = max(len, right - left +
                               1); // update length if current substring (r - l
                                   // + 1) is longer than the previous
            right++;               // move to next charac ter in the string
        }
        return len;
    }
};

// clarifying questions
// Can the input string contain spaces or special characters?
//  Should the result be the actual substring or just the length?
//  Can the string be empty?
