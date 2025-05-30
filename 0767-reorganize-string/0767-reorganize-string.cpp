//  .....BRUTE FORCE APPROACH .............
// Here i can think of is brute force approach where i will generate all possible permutations of string and check each one to see if it satisfies the condition or not. which is no two adjacent  chareacters are same. if a valid one is found return it , if no valid permutation exist i will return empty string. 
// tc :- O(n! * n) Generating all permutations and for each permutation checking validity 
// sc :-  O(n) 

//..........Optimized using Greedy appraoch ...........
//  I first count the frequency of each character and check if the most frequent character exceeds half of the string length — if it does, rearrangement is impossible. Then, I place the most frequent character in even indices first to maximize spacing, and then fill in the rest. This ensures adjacent characters aren’t the same while keeping it linear in time.

class Solution {
public:
    string reorganizeString(string str) {
        // Frequency array to count occurrences of each character (a to z)
        vector<int> hash(26, 0);

        // Step 1: Count frequency of each character in the string
        for (char c : str)
            hash[c - 'a']++;

        int maxFreq = 0;    // Store the highest frequency found
        int letter = 0;     // Index of the character with max frequency

        // Step 2: Find the character with the maximum frequency
        for (int i = 0; i < 26; i++) {
            if (hash[i] > maxFreq) {
                maxFreq = hash[i];  // Update max frequency
                letter = i;         // Store the index of the character
            }
        }

        // Step 3: If the highest frequency is more than (n + 1)/2, return "" (not possible)
        if (maxFreq > (str.length() + 1) / 2)
            return "";

        // Step 4: Create a result array of same size as input
        vector<char> res(str.length());
        int idx = 0;  // Start placing characters at even indices

        // Step 5: First place the most frequent character at even indices
        while (hash[letter]-- > 0) {
            res[idx] = 'a' + letter; // Place character in result
            idx += 2;                // Move to next even index
        }

        // Step 6: Place the remaining characters
        for (int i = 0; i < 26; i++) {
            while (hash[i]-- > 0) {
                // If even indices are filled, start with odd indices
                if (idx >= res.size())
                    idx = 1;

                res[idx] = 'a' + i; // Place character in result
                idx += 2;           // Move to next index (even or odd)
            }
        }

        // Step 7: Convert result vector to string and return
        return string(res.begin(), res.end());
    }
};