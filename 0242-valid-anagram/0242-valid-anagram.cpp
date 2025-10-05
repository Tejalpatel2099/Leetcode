// we are given two strings s and t and needs to return true if it is an anagram of s and if not return false so , valid anagram means that both strings must havce same lengt5h andthey must contain same characters with same frequency. 
// 1. input strings are lowercase only ? 
// so here i can think of is a brute force solution to sort both strings and compare them i mean sort s and t and then if they become equal after sorting they are anagarms so , TC:- O(n log n) for each sort → overall O(n log n)
// and sc :-   O(1) if sorting in-place

//.......optimized ...............
//First, if the two strings have different lengths, they can’t be anagrams — so I return false right away.

//Next, I create a frequency counter for the first string s.
//I go through each character and count how many times each letter appears.

//Then, I go through the second string t, and for every character, I subtract from the frequency count.

//If at any point, the count goes below zero, that means there are more of that character in t than in s, so I return false.

//If I reach the end and all counts are balanced (i.e., no negative values), then both strings have the same characters in the same counts, so they are anagrams — I return true.”  
// Tc :- o(n) and sc :- o(1)

class Solution {
public:
    bool isAnagram(string s, string t) {

        // Step 1: If lengths are not equal, they can't be anagrams
        if (s.size() != t.size()) {
            return false;
        }

        // Step 2: Create a frequency map to count characters in string s
        unordered_map<char, int> freq;

        // Count how many times each character appears in s
        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;  // increment count of character s[i]
        }

        // Step 3: Reduce the count based on characters in string t
        for (int i = 0; i < t.size(); i++) {
            if (freq.count(t[i])) {
                freq[t[i]]--;  // decrease count for character t[i]

                // If count becomes 0, remove it from map 
                if (freq[t[i]] == 0) {
                    freq.erase(t[i]);
                }
            } else {
                // If character in t is not in s or used more times → not anagram
                return false;
            }
        }

        // Step 4: If all counts are balanced, map should be empty
        return freq.empty();  // true if valid anagram, false otherwise
    }
};