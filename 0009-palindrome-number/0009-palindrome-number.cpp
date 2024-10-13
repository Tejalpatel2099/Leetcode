class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        long int x_reverse{0}, n=x, rem{0};
        while(n){
            rem = n%10;
            x_reverse = x_reverse*10+rem;
            n/=10;
        }
        if(x_reverse == x)
            return true;
    return false;
    }
}; 