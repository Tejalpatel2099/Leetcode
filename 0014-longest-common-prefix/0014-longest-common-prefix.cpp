class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      // if the list is empty 
      if (strs.empty()) return "";

    //lets assume first word is prefix 
    string prefix = strs[0];

    // compare prefix with every other word
    for (int i = 1; i < strs.size(); i++) {
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.size()- 1);

            if (prefix.empty()) return "";
        }
    }
    return prefix;
    }
};  