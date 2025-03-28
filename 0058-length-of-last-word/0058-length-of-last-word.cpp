class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;       // length of last word
        int i = s.size() - 1; // starting from end of string

        //skip trailing spaces

            while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // count the length of last word

        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};

