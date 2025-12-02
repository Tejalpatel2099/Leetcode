class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const long long MOD = 1000000007LL;
        int n = points.size();
        if (n < 4) return 0;

        // Count how many points on each y-level
        unordered_map<long long, long long> cnt;
        cnt.reserve(n * 2);
        cnt.max_load_factor(0.7f);
        for (auto &p : points) {
            long long y = p[1];
            cnt[y]++;
        }

        long long sumW = 0;      // sum of w_y
        long long sumWSq = 0;    // sum of w_y^2

        for (auto &kv : cnt) {
            long long c = kv.second;
            if (c >= 2) {
                // w_y = C(c, 2) = c * (c - 1) / 2  (mod MOD)
                long long w = c * (c - 1) / 2 % MOD;
                sumW = (sumW + w) % MOD;
                long long w2 = (w * w) % MOD;
                sumWSq = (sumWSq + w2) % MOD;
            }
        }

        if (sumW == 0) return 0; // no horizontal segments at all

        // Total = (sumW^2 - sumWSq) / 2  mod MOD
        long long res = (sumW * sumW) % MOD;
        res = (res - sumWSq + MOD) % MOD;

        // Multiply by inverse of 2 modulo MOD: (MOD + 1) / 2 since MOD is prime
        long long inv2 = (MOD + 1) / 2;
        res = (res * inv2) % MOD;

        return (int)res;
    }
};