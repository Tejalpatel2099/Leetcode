class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0"; 
        }
        string res;
        bool negative = ( (numerator < 0) ^ (denominator < 0) );
    long long n = llabs((long long)numerator);
    long long d = llabs((long long)denominator);

    if (negative) res.push_back('-');

    // Integer part
    long long integer = n / d;
    res += to_string(integer);

    long long rem = n % d;
    if (rem == 0) return res; // no fractional part

    res.push_back('.');

    // Map remainder -> position in res where its digit starts
    unordered_map<long long, int> remPos;

    while (rem != 0) {
        if (remPos.count(rem)) {
            // Insert '(' at the first occurrence and append ')'
            int pos = remPos[rem];
            res.insert(pos, "(");
            res.push_back(')');
            break;
        }
        remPos[rem] = (int)res.size();

        rem *= 10;
        long long digit = rem / d;
        res.push_back(char('0' + digit));
        rem %= d;
    }

    return res;
    }
};