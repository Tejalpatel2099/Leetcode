class Solution {
public:
// helper function to check if substring is palindrome or not 
bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            // if characters do not match then its is not palindrome 
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true; // if we never found mismatch it is palindrome 
    }

    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                // Try removing one character from either side
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
            left++;
            right--;
        }

        return true; // Already a palindrome
    }
};