class Solution {
public:
    string replaceDigits(string s) {
        for (int i = 1; i < s.size(); i += 2) {
            char previousChar = s[i - 1];
            int shiftAmount = s[i] - '0';
            s[i] = previousChar + shiftAmount;
        }
        return s;
    }
};