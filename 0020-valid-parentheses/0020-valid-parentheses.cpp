class Solution {
public:
    bool isValid(string str) {
        stack<char> st; // Stack to track opening brackets

        // Loop through each character in the string
        for (int i = 0; i < str.size(); i++) {

            // If it's an opening bracket, push it onto the stack
            if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
                st.push(str[i]);
            } else {
                // If it's a closing bracket and stack is empty → invalid
                if (st.empty()) return false;

                // Check if the current closing bracket matches the top of the stack
                if ((str[i] == ')' && st.top() == '(') ||
                    (str[i] == '}' && st.top() == '{') ||
                    (str[i] == ']' && st.top() == '[')) {
                    st.pop(); // Matching pair found → pop the opening bracket
                } else {
                    return false; // Mismatched bracket → invalid
                }
            }
        }

        // If the stack is empty, all brackets were matched → valid
        return st.empty();
    }
};
