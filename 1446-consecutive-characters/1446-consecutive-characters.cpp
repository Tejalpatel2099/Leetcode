class Solution {
public:
    int maxPower(string s) {
        int n = s.size();
        int count = 1;
        int maxCount = 1;

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                count++;
            } else {
                count = 1;
            }
            maxCount = max(count, maxCount);
        }
        return maxCount;
    }
};