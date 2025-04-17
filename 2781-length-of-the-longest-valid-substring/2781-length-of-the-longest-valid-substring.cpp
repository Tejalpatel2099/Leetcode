class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        unordered_set<string> forbid(forbidden.begin(), forbidden.end());
    int maxLen = 0;
    int left = 0;
    int maxForbiddenLen = 0;

    // Find the maximum length of forbidden strings
    for (int i = 0; i < forbidden.size(); i++) {
        if ((int)forbidden[i].size() > maxForbiddenLen) {
            maxForbiddenLen = (int)forbidden[i].size();
        }
    }

    for (int right = 0; right < word.size(); ++right) {
        for (int len = 1; len <= maxForbiddenLen && right - len + 1 >= left; ++len) {
            string sub = word.substr(right - len + 1, len);
            if (forbid.count(sub)) {
                left = right - len + 2;
                break;
            }
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
    }
};