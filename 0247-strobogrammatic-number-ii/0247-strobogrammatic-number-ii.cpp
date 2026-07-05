class Solution {
public:
    vector<string> ans;

    vector<pair<char, char>> pairs = {
        {'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};

    void solve(string& curr, int left, int right, int n) {
        if (left > right) {
            ans.push_back(curr);
            return;
        }

        for (auto [a, b] : pairs) {
            // avoid numbers like "00", "0110"
            if (left == 0 && n > 1 && a == '0')
                continue;

            // middle digit can only be 0, 1, or 8
            if (left == right && a != b)
                continue;

            curr[left] = a;
            curr[right] = b;

            solve(curr, left + 1, right - 1, n);
        }
    }

    vector<string> findStrobogrammatic(int n) {
        string curr(n, ' ');
        solve(curr, 0, n - 1, n);
        return ans;
    }
};