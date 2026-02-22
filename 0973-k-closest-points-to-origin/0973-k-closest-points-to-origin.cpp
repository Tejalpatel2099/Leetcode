class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // max-heap: stores {distanceSquared, index or point}
        priority_queue<pair<long long, int>> pq;

        for (int i = 0; i < (int)points.size(); i++) {
            long long x = points[i][0];
            long long y = points[i][1];
            long long dist = x*x + y*y;

            pq.push({dist, i});

            if ((int)pq.size() > k) {
                pq.pop(); // remove farthest among the kept points
            }
        }

        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans; // any order is fine
    }
};