class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> result;

        int n = digits.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    // All indices must be different
                    if (i == j || j == k || i == k) continue;

                    int d1 = digits[i];
                    int d2 = digits[j];
                    int d3 = digits[k];

                    // Skip if number has leading zero
                    if (d1 == 0) continue;

                    // Only include even numbers
                    if (d3 % 2 != 0) continue;

                    int num = d1 * 100 + d2 * 10 + d3;
                    result.insert(num);  // set ensures uniqueness
                }
            }
        }

        // Convert set to sorted vector
        return vector<int>(result.begin(), result.end());
    }
};
