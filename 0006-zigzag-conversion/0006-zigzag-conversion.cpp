// I am simulating the zigzag movement row by row. I create a list of strings where each index represents a row. As I move through the input string, I add each character to the appropriate row. I use a goingDown flag to change direction when I hit the top or bottom. After placing all characters, I simply combine all the rows to form the final output

// Tc O(n) (where n = number of characters in s)

// Space = O(n) (to store all characters into intermediate rows vector 


class Solution {
public:
    string convert(string s, int numRows) {
        // If only one row or string length is smaller than numRows, no zigzag needed
        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }

        // Create a list to store each row's characters
        vector<string> rows(numRows);

        int currentRow = 0;     // Track the current row
        bool goingDown = false; // Direction flag: true = down, false = up

        // Traverse the string
        for (int i = 0; i < s.length(); i++) {
            // Add the current character to the current row
            rows[currentRow] += s[i];

            // If we are at the top or bottom, reverse the direction
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }

            // Move to the next row depending on direction
            if (goingDown) {
                currentRow++;
            } else {
                currentRow--;
            }
        }

        // Combine all rows to get the final result
        string result = "";
        for (int i = 0; i < rows.size(); i++) {
            result += rows[i];
        }

        return result;
    }
};