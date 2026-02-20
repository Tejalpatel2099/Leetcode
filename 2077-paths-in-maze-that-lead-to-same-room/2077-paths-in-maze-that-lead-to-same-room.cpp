class Solution {
public:
    int numberOfPaths(int n, vector<vector<int>>& corridors) {
        // create adjacency list
        // adj[i] will store al rooms directly connected to room i
        vector<unordered_set<int>> adj(n + 1);

        // fill adj list
        for (auto& edge : corridors) {
            int u = edge[0];
            int v = edge[1];

            // since corridors are bidirectional
            adj[u].insert(v);
            adj[v].insert(u);
        }

        int triangleCount = 0;

        for (auto& edge : corridors) {
            int u = edge[0];
            int v = edge[1];

            for (int neighbours : adj[u]) {
                if (adj[v].count(neighbours)) {
                    triangleCount++;
                }
            }
        }
        return triangleCount / 3; 
    }
};