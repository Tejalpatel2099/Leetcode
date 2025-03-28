class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        std::string ans = "";
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (st.empty()) {
                st.push(ch);
            } else {

                if (ch == st.top()) {
                    st.pop();
                } else {
                    st.push(ch);
                }
            }
        }
        while (!st.empty()) {
            ans = ans + st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};