class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";

        for (string s : strs) {
            // Store length of string followed by '#' and then the string itself
            encoded += to_string(s.size()) + "#" + s;
        }

        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;

        while (i < s.size()) {
            int j = i;

            // Find the position of the '#' delimiter to get the length
            while (s[j] != '#') {
                j++;
            }

            int len = stoi(s.substr(i, j - i)); // Extract the length of the string
            string word = s.substr(j + 1, len); // Extract the word of 'len' characters

            result.push_back(word);

            i = j + 1 + len; // Move to the start of the next encoded word
        }

        return result;
    }
};
