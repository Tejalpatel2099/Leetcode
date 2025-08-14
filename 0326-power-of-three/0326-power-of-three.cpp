// Appraoch (Iterative) 
// if n <= 0 return false 
// then keep dividing n by 3 so that it is divisibnle of 3 
// after all division n becomes 1 then true otherwise false 

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }

        while (n % 3 == 0) {
            n = n / 3;
        }
        return n == 1; 
    }
};

// TC :- log (n)
//SC :- O(1)