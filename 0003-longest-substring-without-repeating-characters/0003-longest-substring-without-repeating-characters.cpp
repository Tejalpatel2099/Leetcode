class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector < int > map(256, -1);

      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      while (right < n) {
        if (map[s[right]] != -1)
          left = max(map[s[right]] + 1, left);

        map[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
      }
      return len;
    }
};


// To do that, we:

//Use two pointers:

//left marks the start of the current window (substring).

//right moves to explore new characters (the end of the window).

//Keep track of the last seen index of each character using a map (or in this case, a vector of size 256 for ASCII).

//When we see a repeating character, it means our current substring is no longer valid.
//So, we move the left pointer to just after the last time that character appeared.

//At each step, we calculate the length of the current window (right - left + 1) and keep the maximum.

