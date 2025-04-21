class Solution {
public:
    int getSum(int a, int b) {
         while (b != 0) {
            unsigned carry = (unsigned)(a & b) << 1; // carry
            a = a ^ b;  // add without carry
            b = carry;  // move carry to b
        }
        return a;
    }
};