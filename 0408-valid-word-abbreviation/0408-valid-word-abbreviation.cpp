class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0; //iterate through word
        int j = 0; //iterate throug abbr

        while (j< abbr.size() && i< word.size()) {          
            int sizeOfAbbr{};
            //If abbr[j] is a digit, then get the offset for 'i' in word
            if (isdigit(abbr[j])) 
            {
                //First digit is a leading zero, return false
                if (abbr[j] == '0') return false;

                while (isdigit(abbr[j])) {
                    sizeOfAbbr = (sizeOfAbbr*10) + abbr[j]- '0';
                    j++;
                }
                i += sizeOfAbbr;
                // We are done moving our pointers here, in the next loop
                // we will  compare the characters in 'word' and 'abbr'     
            }
            // Only check for same characters if we did not find a digit
            else
            {
                if (word[i] != abbr[j]) return false;
                j++;
                i++;
            }
        }
        //Make sure we have traversed the entirety of 'word' and 'abbr'
        return (i == word.length() && j == abbr.length());
    }
};