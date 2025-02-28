class Solution {
public:
    string findValidPair(string s) {
        // Array to count occurrences of digits from 1 to 9
        int count[9] = {0};
        
        // Count the occurrences of each digit from 1 to 9 in the string
        for (int i = 0; i < s.length(); i++) {
            int digit = s[i] - '0';  // Convert character to integer
            if (digit >= 1 && digit <= 9) {  // Only count digits 1 to 9
                count[digit - 1]++;  // Store count of digits in array
            }
        }

        // Traverse the string to find the first valid pair
        for (int i = 0; i < s.length() - 1; i++) {
            int d1 = s[i] - '0';  // First digit of the pair
            int d2 = s[i + 1] - '0';  // Second digit of the pair
            
            // Check if the digits are different and meet the count condition
            if (d1 != d2 && d1 >= 1 && d2 >= 1 && count[d1 - 1] == d1 && count[d2 - 1] == d2) {
                return string(1, s[i]) + string(1, s[i + 1]);
            }
        }
        
        // If no valid pair is found, return an empty string
        return "";
    }
};
