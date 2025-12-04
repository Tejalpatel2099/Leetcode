class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> g(n);
        vector<int> deg(n, 0);

        for (auto &e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
            deg[a]++; deg[b]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 1) q.push(i); // initial leaves
        }

        int remaining = n;
        while (remaining > 2) {
            int layer = (int)q.size();
            remaining -= layer;

            while (layer--) {
                int leaf = q.front(); q.pop();
                for (int nei : g[leaf]) {
                    if (--deg[nei] == 1) q.push(nei);
                }
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
