class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long totalShift = 0;

        for (int i = s.size() - 1; i >= 0; i--) {

            totalShift = (totalShift + shifts[i]) % 26;

            s[i] = 'a' + (s[i] - 'a' + totalShift) % 26;
        }

        return s;
    }
};