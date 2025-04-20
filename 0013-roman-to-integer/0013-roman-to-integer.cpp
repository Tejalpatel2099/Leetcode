class Solution {
public:
    int romanToInt(string s) {
        //step 1:- create a map of char and int 
        unordered_map<char, int> roman = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };
        int result = 0;  // to store result of integer value 
        for (int i = 0; i < s.length(); i++) {
        int current = roman[s[i]];  // so here get value of current 
         int next = 0;

          if (i + 1 < s.length()) {
            next = roman[s[i + 1]];
        }

        // Step 3: Decide to add or subtract based on next character
        if (current < next) {
            result = result - current;
        } else {
            result = result +  current;
        }
    }

    return result;

    }
};