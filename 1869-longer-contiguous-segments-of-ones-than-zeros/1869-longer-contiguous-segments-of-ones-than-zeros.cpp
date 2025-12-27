class Solution {
public:
    bool checkZeroOnes(string s) {
        int maxcountOne = 0;
        int macountZero = 0;
        int countOnes = 0;
        int countZeros = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                countOnes++;
                countZeros = 0;
            } else {
                countZeros++;
                countOnes = 0;
            }
            maxcountOne = max(countOnes, maxcountOne);
            macountZero = max(countZeros, macountZero);
        }

        if (maxcountOne == macountZero || maxcountOne < macountZero) {
            return false;
        }
        return true;
    }
};