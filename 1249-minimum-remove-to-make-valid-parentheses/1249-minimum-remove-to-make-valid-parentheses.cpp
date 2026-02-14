class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_set<int> badIndex;
        stack<int> st;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
                cout << "inserting index stack" << i << endl;
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    cout << "inserting badindex " << i << endl;
                    // s.erase(i,1);  // if stack is empty there is no brackets
                    // so add its index to bad index
                    badIndex.insert(i);
                }
            }
        }

        while (!st.empty()) { // if stack is empty add other mismatched to bad
                              // index
            badIndex.insert(st.top());
            cout << "inserting from stack in badindex" << st.top() << endl;
            st.pop();
        }
        

        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            cout <<" loop index "<< i << endl;
            if (!badIndex.contains(i)) {
                // ans = ans + s[i];
                ans.push_back(s[i]);
                // s.erase(i, 1);
                cout <<"adding index "<< i <<endl;
            }
        }
        return ans;
    }
};