class Solution {
public:
    string toGoatLatin(string sentence) {
        unordered_set<char> vowels = {'a','e','i','o','u'};
        stringstream ss(sentence);
        string word, result;
        int index = 1;

        while (ss >> word) {
            char first = tolower(word[0]);

            if (vowels.count(first)) {
                word += "ma";
            } else {
                word = word.substr(1) + word[0] + "ma";
            }

            word = word + string (index, 'a');
            index++;

            if (!result.empty()) result += " ";
            result = result + word; 
        }
        return result;
    }
};