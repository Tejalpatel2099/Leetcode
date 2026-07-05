class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> mp = {
            {'0', '0'},
            {'1', '1'},
            {'6', '9'},
            {'8', '8'},
            {'9', '6'}
        };

        int l = 0;
        int r = num.size() - 1;

        while (l <= r) {
            
            if (mp.find(num[l]) == mp.end())
                return false;

            if (mp[num[l]] != num[r])
                return false;

            l++;
            r--;
        }

        return true;
    }
};