class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // base for valid length calculation
        int best = 0;

        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else { // ')'
                st.pop();  // try to match with a '('
                if (st.empty()) {
                    // no matching '(', mark this as the new base
                    st.push(i);
                } else {
                    // valid substring length ends at i
                    best = max(best, i - st.top());
                }
            }
        }
        return best;
    }
};