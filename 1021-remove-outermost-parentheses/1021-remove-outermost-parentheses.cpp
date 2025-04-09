class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int depth = 0;

        for ( int i = 0; i < s.size(); i++) {
            char c = s[i];  // current charcater 

            if (c == '(') {
                // when we see '(' increase depth
                if (depth > 0) {
                    result = result + c;
                }
                depth++;
            } else if (c == ')') {
                depth--;

                if (depth > 0) {
                    result = result + c;
                }
            }
        }
        return result;
    }
};