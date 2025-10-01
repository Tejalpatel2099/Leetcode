class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> blocks;
    int bal = 0, start = 0;

    for (int i = 0; i < (int)s.size(); ++i) {
        bal += (s[i] == '1') ? 1 : -1;
        if (bal == 0) {
            // Correct inner length: (i - start - 1)
            string inner = s.substr(start + 1, i - start - 1);
            string innerMax = makeLargestSpecial(inner);
            blocks.push_back("1" + innerMax + "0");
            start = i + 1;
        }
    }

    sort(blocks.begin(), blocks.end(), greater<string>());
    string res;
    for (auto& b : blocks) res += b;
    return res;
    }
};