class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;  //initializes i to the index of the last character in the string. 
        int length = 0; // counter length to keep track of the length of the last word.

        while (s[i] == ' ') {   //This loop moves the index i backward until it points to a non-space character,
            i--;  
        }
        while (i >= 0 && s[i] != ' ') { //continues to move the index i backward, incrementing the length counter, until it encounters a space or reaches the beginning of the string.
            length++;
            i--;
        }
        return length;
    }
};