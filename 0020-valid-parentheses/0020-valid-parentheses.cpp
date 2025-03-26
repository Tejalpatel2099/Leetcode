class Solution {
public:
    bool isValid(string str) {
        stack<char> st;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
                st.push(str[i]);
            } else {
                if (st.empty()) return false;

                if ((str[i] == ')' && st.top() == '(') ||
                    (str[i] == '}' && st.top() == '{') ||
                    (str[i] == ']' && st.top() == '[')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
