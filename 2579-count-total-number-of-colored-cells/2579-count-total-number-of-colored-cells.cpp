class Solution {
public:
    long long coloredCells(int n) {
        if(n == 1) return 1;
        n--;
        return ((long long)(n)*(long long)(8+(n-1)*4))/2 + 1;
    }
};