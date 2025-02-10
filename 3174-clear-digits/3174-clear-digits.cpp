class Solution {
public:
    string clearDigits(string s) {
        int i = 0;
        string ans = "";

        for (int i = 0; i < s.length(); i++) {
            if (!isdigit(s[i])) { // if that index is digit then pop back to
                                  // last char to ans string and if not then
                                  // simple push backl to ans string
                ans = ans + s[i];
            } else if (!ans.empty()) {
                ans.pop_back();
            }
        }
        return ans;
    }
};
