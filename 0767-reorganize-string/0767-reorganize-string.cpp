//  .....BRUTE FORCE APPROACH .............
// Here i can think of is brute force approach where i will generate all possible permutations of string and check each one to see if it satisfies the condition or not. which is no two adjacent  chareacters are same. if a valid one is found return it , if no valid permutation exist i will return empty string. 
// tc :- O(n! * n) Generating all permutations and for each permutation checking validity 
// sc :-  O(n) 

//..........Optimized using Greedy appraoch ...........
// To solve this problem efficiently, I consider the role of the character with the highest frequency. If this character occurs more than (n + 1)/2 times, there’s no way to rearrange the string to avoid duplicates, so I return "". Otherwise, I can place this character at alternate indices to maximize spacing, and then fill in the remaining characters. This approach ensures no two same characters are adjacent and is linear in time and space, making it optimal. 
//  Case 1: Max frequency > (n + 1) / 2 → Impossible
//If any character appears more than half the length of the string (rounded up), then even after placing it at every alternate index, we’ll run out of gaps and be forced to place two same characters together — which is not allowed.
// Case 2: Max frequency == (n + 1) / 2 → Perfect Fit
//If the max frequency is exactly half or half rounded up, then we can place that character at all even indices and then place the rest at odd positions.
//  Case 3: Max frequency < (n + 1) / 2 → Always Possible
//This is the most general and most common case. If the most frequent character occurs less than half, we can always space it out properly and fill in the remaining characters between them

//Time Complexity: O(n)
// Space Complexity: O(n)

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