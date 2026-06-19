class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int height = 0;
        int current = 0;

        for (int i = 0; i < gain.size(); i++) {
            current = current + gain[i];
            if (current > height) {
                height = max(height,current);
            }
        }
        return height;
    }
};