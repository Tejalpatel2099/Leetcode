class Solution {
public:
    int findParent(int node, vector<int>& parent) {
        if (parent[node] != node)
            parent[node] = findParent(parent[node], parent); // Path compression
        return parent[node];
    }

    void unionSet(int u, int v, vector<int>& parent) {
        int pu = findParent(u, parent);
        int pv = findParent(v, parent);
        if (pu != pv) {
            parent[pu] = pv;
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;

        int components = n;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            int pu = findParent(u, parent);
            int pv = findParent(v, parent);

            if (pu != pv) {
                unionSet(pu, pv, parent);
                components--;
            }
        }

        return components;
    }
};
