class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;

    void backtrack(int start, int n, int k) {
        // If current combination has k elements
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        for (int i = start; i <= n; i++) {
            current.push_back(i);          // choose
            backtrack(i + 1, n, k);       // explore
            current.pop_back();           // unchoose (backtrack)
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtrack(1, n, k);
        return result;
    }
};