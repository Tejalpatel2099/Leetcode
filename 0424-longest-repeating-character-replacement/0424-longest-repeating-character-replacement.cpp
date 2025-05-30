// "I’m given a string s and an integer k. I can change at most k characters in s to any other uppercase character. My goal is to return the length of the longest substring that contains only one repeated character after at most k changes."

// clarifying questions 
// 1. 

// so here i can think of is BRUTE FORCE APPROACH were i wil try all posible substrings of s and for each substring, count the frequency of each character. find the most frequent character in that substring. and check if we can change teh reamining characters (total length - max frequency) within k changes. if yes then i will update max length. Tc :- O(n3) and sc :- O(1) 


//.,................SLIDING WINDOW .........................
//We maintain a window that contains the most frequent character, and if the number of characters to be changed exceeds k, we shrink the window.
// here will sliding window technique with two pointers i and j and hashmap to track character counts.
// tc :- O(n) and sc :_ O(1)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i = 0, j = 0;           // i = start of window, j = end of window
        int maxi = 0;              // stores the max frequency of any character in the current window
        unordered_map<char, int> mp; // frequency map of characters in the window
        int ans = -1;              // stores the final answer (max length of valid substring)

        while (j < n) {
            mp[s[j]]++;                         // include character s[j] in the window
            maxi = max(maxi, mp[s[j]]);         // update max frequency character in the window

            // If the number of characters to be changed is more than k
            // (window size - max frequency > k), then shrink the window
            if ((j - i + 1) - maxi > k) {
                mp[s[i]]--;   // remove the character at the start of the window
                i++;          // move the start of the window forward
            }

            // update answer with the current valid window size
            ans = max(ans, j - i + 1);
            j++; // expand the window
        }

        return ans; // return the length of the longest valid substring
    }
};
// clarifying questions 
// Can the input string contain only uppercase English letters?
//Can k be greater than the length of the string?
//Do I need to return the substring or just its length?
//Can I change characters multiple times or only once per character?
