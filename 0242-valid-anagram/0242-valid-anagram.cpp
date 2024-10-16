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
