class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.length();

        for (int center = 0; center < 2 * n - 1; ++center) {
            int left = center / 2;
            int right = left + (center % 2);

            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
        }

        return count;
    }
};