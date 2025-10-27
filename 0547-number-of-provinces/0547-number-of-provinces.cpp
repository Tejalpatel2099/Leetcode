class Solution {
private:
    // Helper DFS function to visit all connected cities from a given city (node)
    void dfs(int node, vector<vector<int>>& adjList, vector<int>& vis) {
        vis[node] = 1; // Mark current city as visited

        // Go through all cities connected to the current city
        for (int v : adjList[node]) {
            // If the connected city is not yet visited, call DFS for it
            if (!vis[v]) 
                dfs(v, adjList, vis);
        }
    }

public:
    // Main function to find number of provinces
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = (int)isConnected.size();  
        // 'n' = number of cities (rows = columns in the matrix)

        // Create an adjacency list representation of the graph
        vector<vector<int>> adjList(n);
        // Each index 'i' represents a city, and adjList[i] stores all directly connected cities

        // Convert the input matrix 'isConnected' into an adjacency list
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) { 
                // Only check upper triangle of the matrix since the graph is undirected
                if (isConnected[i][j] == 1) {
                    // If city i and j are directly connected, add each other to their lists
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        // Create a visited array to track which cities we've already explored
        vector<int> vis(n, 0); // 0 = not visited, 1 = visited

        int count = 0; // To count the number of provinces

        // Go through each city
        for (int i = 0; i < n; ++i) {
            // If this city hasn't been visited, it means a new province starts here
            if (!vis[i]) {
                ++count;  // Found a new province
                dfs(i, adjList, vis);  // Explore all cities in this province
            }
        }

        // Return the total number of provinces
        return count;
    }
};
