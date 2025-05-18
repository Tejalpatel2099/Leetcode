class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        int wordLen = words[0].length();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        unordered_map<string, int> wordMap;

        // Frequency map of words
        for (string& word : words)
            wordMap[word]++;

        // Try all starting points in wordLen range
        for (int i = 0; i < wordLen; i++) {
            unordered_map<string, int> windowMap;
            int left = i, count = 0;

            // Slide the window by wordLen
            for (int j = i; j + wordLen <= s.length(); j += wordLen) {
                string word = s.substr(j, wordLen);
                if (wordMap.find(word) != wordMap.end()) {
                    windowMap[word]++;
                    count++;

                    // If word occurs too many times, shrink from left
                    while (windowMap[word] > wordMap[word]) {
                        string leftWord = s.substr(left, wordLen);
                        windowMap[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    // If valid window found
                    if (count == wordCount)
                        result.push_back(left);
                } else {
                    // Invalid word → reset everything
                    windowMap.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }

        return result;
    }
};
