class Solution {
private:
    void dfs(int node, vector<vector<int>>& adjList, vector<int>& vis) {
        vis[node] = 1;
        for (int v : adjList[node]) {
            if (!vis[v]) dfs(v, adjList, vis);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = (int)isConnected.size();
        vector<vector<int>> adjList(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) { // avoid dup checks
                if (isConnected[i][j] == 1) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, 0);
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                ++count;
                dfs(i, adjList, vis);
            }
        }
        return count;
    }
};
