
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int> st;
        vector<bool> remove(n, false);

        // Step 1: Scan the string
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } 
            else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();   // matched with '('
                } else {
                    remove[i] = true; // extra ')'
                }
            }
        }

        // Step 2: Remaining '(' in stack are invalid
        while (!st.empty()) {
            remove[st.top()] = true;
            st.pop();
        }

        // Step 3: Build final answer
        string ans;
        for (int i = 0; i < n; i++) {
            if (!remove[i]) {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};