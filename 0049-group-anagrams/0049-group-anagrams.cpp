class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> anagrams;

        // Populate the hash map with sorted keys
        for (int i = 0; i < strs.size(); i++) {
            string sortedString = strs[i];
            sort(sortedString.begin(), sortedString.end());
            mp[sortedString].push_back(strs[i]);
        }

        // Extract values from the hash map into the output vector
        auto it = mp.begin();
        while (it != mp.end()) {
            anagrams.push_back(it->second);
            ++it;
        }

        return anagrams;
    }
};