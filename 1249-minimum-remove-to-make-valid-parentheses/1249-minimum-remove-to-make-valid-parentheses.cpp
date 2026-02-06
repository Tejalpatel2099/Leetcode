
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_set<int>BI;
        stack<int>st;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            else if (s[i] == ')') {
                if (st.empty())BI.insert(i);
                else st.pop();

            }
        }
        while (!st.empty()) {
            BI.insert(st.top());
            st.pop();
        }
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            if (!BI.contains(i)) {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};