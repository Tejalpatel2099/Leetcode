class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Adjacency list
        unordered_map<int, vector<int>> graph;
        // In-degree array
        vector<int> in_degree(numCourses, 0);
        
        // Build graph and in-degree array
        for (const auto& pair : prerequisites) {
            int dest = pair[0];
            int src = pair[1];
            graph[src].push_back(dest);
            in_degree[dest]++;
        }

        // Initialize queue with courses having in-degree of 0
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            order.push_back(course);
            for (int neighbor : graph[course]) {
                in_degree[neighbor]--;
                if (in_degree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if (order.size() == numCourses) {
            return order;
        } else {
            return {};
        }
    }
};