class Solution {
public:
         int reverse(int x) {
       long  result = 0; 

        while( x !=  0) {
            int lastDigit = x % 10;
            if ( result > INT_MAX/10) {
                return 0; 
            }else if (result < INT_MIN/10) {
                return 0;
            }
            result = (result * 10) + lastDigit;
            x = x / 10;
        }
        return result;
    }     
};