class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";

        // Reverse the entire string
        reverse(s.begin(), s.end());

        for (int i = 0; i < n; i++) {
            string word = "";

            // Extract each word
            while (i < n && s[i] != ' ') {
                word = word +  s[i];
                i++;
            }

            // Reverse the individual word to correct its order
            reverse(word.begin(), word.end());

            // Add the word to the result if it is non-empty
            if (!word.empty()) {
                if (!ans.empty()) {
                    ans += " "; // Add a space before appending the next word
                }
                ans = ans +  word;
            }
        }

        return ans; // Return the final result
    }
};
