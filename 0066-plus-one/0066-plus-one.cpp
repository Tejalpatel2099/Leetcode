class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // start fropm last and move to left

        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0; // if the didgit is 9 we set it to 0 and carryu 1 to
                           // next left didgit
        }
        digits.insert(digits.begin(),1); // if all digits are 9 then add 1 at start
        return digits;
    }
};