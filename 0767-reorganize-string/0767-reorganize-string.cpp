class Solution {
public:
    string reorganizeString(string str) {
        vector<int> hash(26, 0);

        // Count character frequencies
        for (char c : str)
            hash[c - 'a']++;

        int maxFreq = 0, letter = 0;

        // Find the character with the maximum frequency
        for (int i = 0; i < 26; i++) {
            if (hash[i] > maxFreq) {
                maxFreq = hash[i];
                letter = i;
            }
        }

        // If the most frequent character is too frequent, return ""
        if (maxFreq > (str.length() + 1) / 2)
            return "";

        vector<char> res(str.length());
        int idx = 0;

        // Fill all even indexes with the most frequent character
        while (hash[letter]-- > 0) {
            res[idx] = 'a' + letter;
            idx += 2;
        }

        // Fill the rest of the characters
        for (int i = 0; i < 26; i++) {
            while (hash[i]-- > 0) {
                if (idx >= res.size())
                    idx = 1;
                res[idx] = 'a' + i;
                idx += 2;
            }
        }

        return string(res.begin(), res.end());
    }
};
