// we are given two strings s and t and needs to return true if it is an anagram of s and if not return false so , valid anagram means that both strings must havce same lengt5h andthey must contain same characters with same frequency. 
// 1. input strings are lowercase only ? 
// so here i can think of is a brute force solution to sort both strings and compare them i mean sort s and t and then if they become equal after sorting they are anagarms so , TC:- O(n log n) for each sort → overall O(n log n)
// and sc :-   O(1) if sorting in-place

//.......optimized ...............
// we can improve this to O(n) time using hashmap or array to count character frequenceies. 
// if length differs return false and create a frequency count of each character in s , decrese the same count as we go through s , and if any count goes below zero -> not an anagram.  
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
