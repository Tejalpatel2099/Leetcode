// I’m given a string s that contains only '(', ')', '{', '}', '[', and ']'.I need to return true if the brackets are balanced — that means:Every opening bracket has a matching closing bracket of the same type Brackets must close in the correct order
// Questions :- 
// Can I assume: The string contains only bracket characters?
// The input can be empty — and if it is, should I return true?

//........Stack ......
// here i can think of is using a stack to track open brackets so basically I scan the string left to right and if i see opening bracket , i will push the code onto stack and if i see closing bracket i check if the stack is empty -> return false and if the top of stack is matchin opening bracket -> pop it a nd if it is mismatch -> return fasle At the end, the stack should be empty for the string to be valid.
//Time Complexity: O(n) We loop through all n characters in the string exactly once.

// Space Complexity: O(n) the stack stores all opening brackets

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
