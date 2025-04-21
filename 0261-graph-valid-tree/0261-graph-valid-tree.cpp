class Solution {
public:
     bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false; // Check tree property
        
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        if (!dfs(0, -1, adj, visited)) return false;

        // Ensure all nodes were visited (connected)
        for (bool v : visited) {
            if (!v) return false;
        }

        return true;
    }

private:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
        if (visited[node]) return false;
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue; // Skip the edge we came from
            if (!dfs(neighbor, node, adj, visited)) return false;
        }

        return true;
    }
};