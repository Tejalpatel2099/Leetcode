class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> result;
        unordered_map<char, string> phoneMap = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        backtrack(digits, 0, "", phoneMap, result);
        return result;
    }

private:
    void backtrack(const string& digits, int index, string path,
                   unordered_map<char, string>& phoneMap, vector<string>& result) {
        if (index == digits.length()) {
            result.push_back(path);
            return;
        }

        for (char c : phoneMap[digits[index]]) {
            backtrack(digits, index + 1, path + c, phoneMap, result);
        }
    }
};
