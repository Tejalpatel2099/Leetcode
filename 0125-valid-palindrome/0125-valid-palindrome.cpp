class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int end = n - 1;
        while (start <= end) {
           if (!isalnum(s[start])) {
                start++;
                continue;
            }
            if (!isalnum(s[end])) {
                end--;
                continue;
            }
            char a = tolower(s[start]);
            char b = tolower(s[end]); 

            if (a != b) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
};