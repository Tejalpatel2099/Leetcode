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
        if (s.size() != t.size()) {
            return false;  // If lengths are different, they can't be anagrams.
        }

        unordered_map<char, int> freq;
        
        // Count frequency of each character in string s
        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
        }

        // Subtract frequency based on string t
        for (int i = 0; i < t.size(); i++) {
            if (freq.count(t[i])) {
                freq[t[i]]--;
                if (freq[t[i]] == 0) {
                    freq.erase(t[i]);
                }
            } else {
                return false;  // If a character in t doesn't exist in s, not an anagram.
            }
        }

        // If the map is empty, it's an anagram
        return freq.empty();
    }
};
