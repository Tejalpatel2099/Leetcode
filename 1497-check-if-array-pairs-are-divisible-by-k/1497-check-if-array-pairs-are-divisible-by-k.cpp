class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false); cin.tie(NULL);
    }
    bool canArrange(vector<int>& arr, int k) {
        bool can = true;
        int mp[k];
        memset(mp, 0, sizeof(mp));

        // Count occurrences of each remainder
        for (auto &x : arr) {
            x = ((x % k) + k) % k; // Ensure non-negative remainder
            mp[x]++;
        }

        // Check pairing conditions
        for (int i = 0; i < k; ++i) {
            if (i == 0) {
                // Remainder 0 must appear in even count
                can &= mp[i] & 1 ^ 1; 
                continue;
            }
            int req = k - i;
            can &= mp[req] == mp[i]; // Remainders must match
        }

        return can;
    }
};