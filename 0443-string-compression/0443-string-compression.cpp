class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> compressed; // Temporary vector to store the compressed result

        int n = chars.size();
        for (int i = 0; i < n; ) {
            char ch = chars[i];
            int count = 0;

            // Count occurrences of the current character
            while (i < n && chars[i] == ch) {
                count++;
                i++;
            }

            // Add the character
            compressed.push_back(ch);

            // Add the count if greater than 1
            if (count > 1) {
                string str = to_string(count);
                for (char dig : str) {
                    compressed.push_back(dig);
                }
            }
        }

        // Copy compressed result back to the original vector
        chars = compressed;

        // Return the new length
        return chars.size();
    }
};
