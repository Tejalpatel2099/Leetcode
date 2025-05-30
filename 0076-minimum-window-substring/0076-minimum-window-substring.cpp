class Solution {
public:
    string minWindow(string s, string t) {
        // Edge case: if s is shorter than t, no valid window exists
        if (s.length() < t.length()) {
            return "";
        }

        // Step 1: Count the frequency of each character in string t
        unordered_map<char, int> charCount;
        for (char ch : t) {
            charCount[ch]++;
        }

        int targetCharsRemaining = t.length(); // Number of characters we still need to find in the current window
        int minWindow[2] = {0, INT_MAX};       // Store the start and end indices of the smallest valid window
        int startIndex = 0;                    // Left boundary of the current window

        // Step 2: Expand the window using endIndex
        for (int endIndex = 0; endIndex < s.length(); endIndex++) {
            char ch = s[endIndex];

            // If the character is needed (present in t and still has positive count), decrease the target
            if (charCount.find(ch) != charCount.end() && charCount[ch] > 0) {
                targetCharsRemaining--;
            }

            // Decrease the count of the current character in the map
            charCount[ch]--;

            // Step 3: If all target characters are found in the window
            if (targetCharsRemaining == 0) {
                // Try to shrink the window from the left
                while (true) {
                    char charAtStart = s[startIndex];

                    // If removing s[startIndex] breaks the requirement, stop shrinking
                    if (charCount.find(charAtStart) != charCount.end() && charCount[charAtStart] == 0) {
                        break;
                    }

                    // Else, add the character back and move the left boundary forward
                    charCount[charAtStart]++;
                    startIndex++;
                }

                // Update the result if current window is smaller than the previous best
                if (endIndex - startIndex < minWindow[1] - minWindow[0]) {
                    minWindow[0] = startIndex;
                    minWindow[1] = endIndex;
                }

                // Now move startIndex one step forward to look for the next valid window
                charCount[s[startIndex]]++;     // Since we are removing s[startIndex] from the window
                targetCharsRemaining++;         // We now need one more character again
                startIndex++;                   // Move window's left boundary
            }
        }

        // Step 4: Return the smallest window substring
        // If minWindow[1] is still INT_MAX, no valid window was found
        return minWindow[1] >= s.length() ? "" : s.substr(minWindow[0], minWindow[1] - minWindow[0] + 1);        
    }
};

// Tc :-   O(n + m)
//sc :- O(m) — for storing frequency of characters from string t.
