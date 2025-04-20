class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int sign = 1; // 1 for '+', -1 for '-'
        stack<int> stk;
        int num = 0;

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];

            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            } else if (c == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            } else if (c == '(') {
                stk.push(result);
                stk.push(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += sign * num;
                num = 0;
                result *= stk.top();
                stk.pop(); // sign before '('
                result += stk.top();
                stk.pop(); // result calculated before '('
            }
            // ignore spaces
        }

        if (num != 0) {
            result += sign * num;
        }

        return result;
    }
};