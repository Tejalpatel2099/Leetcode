class Solution {
public:
    string processStr(string s) {
        string ans = "";

        for (char c : s) {
            if (std::isalpha(c)) {

                ans.push_back(c);
            } else if (c == '*') {

                if (!ans.empty()) {
                    ans.pop_back();
                }
            } else if (c == '#') {

                ans = ans + ans;
            } else if (c == '%') {

                std::reverse(ans.begin(), ans.end());
            }
        }

        return ans;
    }
};