class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string term = "1";

        for (int i = 2; i <= n; ++i) {
            string next = "";
            int count = 1;
            for (int j = 1; j < term.size(); ++j) {
                if (term[j] == term[j - 1]) {
                    count++;
                } else {
                    next += to_string(count) + term[j - 1];
                    count = 1;
                }
            }
            // Add the last group
            next += to_string(count) + term.back();
            term = next;
        }

        return term;
    }
};
