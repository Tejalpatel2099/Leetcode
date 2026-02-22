//"One way to solve this is to generate all strings of length 2n consisting of '(' and ')', and then filter only valid ones. But this has exponential complexity — O(2^2n) — since we’d generate all combinations and then check each for validity."

// "To improve this, I’ll use backtracking to only generate valid sequences during construction." ✅

// 🔹 3. Backtracking Strategy
// Here’s how you can explain the approach step-by-step:

// "I’ll use backtracking with these key decisions:"

// At each step, I can either add a '(' if I haven’t used all n opening brackets.

// Or I can add a ')' if the number of ')' used so far is less than the number of '(' used (to maintain validity).

// Once the current string reaches length 2n, it's added to the result.

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& result, string current, int open, int close, int max) {
        if (current.length() == max * 2) {
            result.push_back(current);
            return;
        }
// // Add opening parenthesis if we still have some left
        if (open < max) {
            backtrack(result, current + "(", open + 1, close, max);
        }
// Add closing parenthesis if it won't invalidate the string
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, max);
        }
    }
};