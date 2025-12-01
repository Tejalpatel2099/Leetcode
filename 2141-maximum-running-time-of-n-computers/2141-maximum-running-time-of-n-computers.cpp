class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long total = 0;
        for (int b : batteries) total += b;

        long long low = 0, high = total / n;

        auto canRun = [&](long long T) {
            long long sum = 0;
            for (long long b : batteries) {
                sum += min(b, T);
                if (sum >= T * n) return true;
            }
            return sum >= T * n;
        };

        while (low < high) {
            long long mid = (low + high + 1) / 2;
            if (canRun(mid)) low = mid;
            else high = mid - 1;
        }

        return low;
    }
};
