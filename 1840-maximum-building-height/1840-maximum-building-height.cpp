class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        vector<pair<long long, long long>> r;

        // Add all given restrictions
        for (auto &x : restrictions) {
            r.push_back({x[0], x[1]});
        }

        // Building 1 must be height 0
        r.push_back({1, 0});

        // Maximum possible height at building n is n - 1
        r.push_back({n, n - 1});

        // Sort by building id
        sort(r.begin(), r.end());

        // Merge duplicate building ids
        vector<pair<long long, long long>> v;
        for (auto &p : r) {
            if (!v.empty() && v.back().first == p.first) {
                v.back().second = min(v.back().second, p.second);
            } else {
                v.push_back(p);
            }
        }

        int m = v.size();

        // Left to right pass
        for (int i = 1; i < m; i++) {
            long long distance = v[i].first - v[i - 1].first;
            v[i].second = min(v[i].second, v[i - 1].second + distance);
        }

        // Right to left pass
        for (int i = m - 2; i >= 0; i--) {
            long long distance = v[i + 1].first - v[i].first;
            v[i].second = min(v[i].second, v[i + 1].second + distance);
        }

        long long answer = 0;

        // Find max height between every two restricted buildings
        for (int i = 1; i < m; i++) {
            long long id1 = v[i - 1].first;
            long long h1 = v[i - 1].second;

            long long id2 = v[i].first;
            long long h2 = v[i].second;

            long long distance = id2 - id1;

            long long maxPeak = (h1 + h2 + distance) / 2;

            answer = max(answer, maxPeak);
        }

        return answer;
    }
};