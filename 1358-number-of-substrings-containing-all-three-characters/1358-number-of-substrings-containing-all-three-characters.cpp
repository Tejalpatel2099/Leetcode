class Solution {
public:
    int numberOfSubstrings(string s) {
     int count = 0, j = 0;
        int lastSeen[3] = {0, 0, 0}; // array to count 'a', 'b', 'c'

        for (int i = 0; i < s.size(); ++i) {
            lastSeen[s[i] - 'a']++;

            while (lastSeen[0] > 0 && lastSeen[1] > 0 && lastSeen[2] > 0) {
                count = count + s.size() - i;
                lastSeen[s[j] - 'a']--;
                j++;
            }
        }
        return count;
    }
};