class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();

        vector<int> arr(n + 1, 0);

        for (auto& query : shifts) {
            int start = query[0];
            int end = query[1];
            int direction = query[2];

            int value;

            if (direction == 1) {
                value = 1;
            } else {
                value = -1;
            }

            arr[start] += value;
            arr[end + 1] -= value;
        }

        int totalShift = 0;

        for (int i = 0; i < n; i++) {
            totalShift += arr[i];

            int position = s[i] - 'a';

            position = (position + totalShift) % 26;

            if (position < 0) {
                position += 26;
            }

            s[i] = 'a' + position;
        }

        return s;
    }
};