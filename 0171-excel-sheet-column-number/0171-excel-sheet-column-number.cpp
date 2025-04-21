class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;

        for (char ch : columnTitle) {
            // Convert character to a number: 'A' = 1, ..., 'Z' = 26
            int value = ch - 'A' + 1;

            // Shift result left (multiply by 26) and add current letter's value
            result = result * 26 + value;
        }

        return result;
    }
};