class ValidWordAbbr {
public:
    unordered_map<string, unordered_set<string>> mp;

    string getAbbr(string word) {
        int n = word.size();

        if (n <= 2) return word;

        return string(1, word[0]) + to_string(n - 2) + string(1, word[n - 1]);
    }

public:
    ValidWordAbbr(vector<string>& dictionary) {
        for (string word : dictionary) {
            string abbr = getAbbr(word);
            mp[abbr].insert(word);
        }
    }

    bool isUnique(string word) {
        string abbr = getAbbr(word);

        // No word has this abbreviation
        if (mp.find(abbr) == mp.end()) {
            return true;
        }

        // Only this same word has this abbreviation
        if (mp[abbr].size() == 1 && mp[abbr].count(word)) {
            return true;
        }

        return false;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */