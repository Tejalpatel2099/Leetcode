//"I start with a pointer i to traverse the string, a sign variable initialized to 1 assuming positive input, and a result variable of type long to hold the number as it's being built.
//We need to skip any leading whitespace characters, as they should be ignored for the conversion process.
//If we encounter a '+' or '-', we record the sign accordingly. If neither is found, we assume the number is positive. 
//We then process each digit character, converting it from char to int, and add it to our result. We multiply the previous result by 10 and add the new digit—this simulates how decimal numbers work
// To avoid integer overflow, I check if the running result exceeds the 32-bit signed integer limits and clamp it to INT_MIN or INT_MAX if necessary.
// Finally, I return the signed result. Since result was of type long to handle overflow during computation, I cast it back to int when returning

//time complexity is O(n) because we process each character once, and the space complexity is O(1) since we don’t use any extra data structures.



class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long result = 0;

        // Step 1: Skip leading whitespaces
        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        // Step 2: Check sign
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Read digits and build result
        while (i < s.length() && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            // Step 4: Clamp to 32-bit signed int limits
            if (sign * result <= INT_MIN) return INT_MIN;
            if (sign * result >= INT_MAX) return INT_MAX;

            i++;
        }

        return static_cast<int>(sign * result);
    }
};
