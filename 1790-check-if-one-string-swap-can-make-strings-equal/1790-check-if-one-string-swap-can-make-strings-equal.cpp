class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) {
        return true;
        }
    vector<int> differentIndices;

    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) {
            differentIndices.push_back(i);
        }
    }

    if (differentIndices.size() != 2) return false;
    
    int i = differentIndices[0], j = differentIndices[1];

  
    swap(s1[i], s1[j]);

    return s1 == s2;
}

};