// Questions 
// 1. Can the number of courses be 0? (Edge case)?
// 2.  Can there be duplicate prerequisites? (e.g., [1, 0] appears twice)
// 3. Is it guaranteed that the input is valid
// 4. Do we need to return the actual course order or just check if it's possible?

//This problem is about detecting a cycle in a directed graph, where each course is a node and prerequisites form edges.
// If there's a cycle, it means some courses are stuck waiting on each other, so it's impossible to finish all courses I treat this as a directed graph where each course is a node and prerequisites are directed edges. If there's a cycle, some courses depend on each other, making it impossible to complete all. So, the goal is to detect if the graph has a cycle.

//..........DFS ...............
// I used DFS to detect cycles. I track nodes using two arrays — one to check if a node was visited, and another to check if it’s in the current recursion path.
// If during DFS I revisit a node in the recursion path, it means there's a cycle.
// If no cycle is found after checking all nodes, it’s possible to finish all courses.
// Time Complexity: O(V * E) — In the worst case, for each course, we scan all prerequisites. 
// SC:- O(V) — for vis[] and rec[]

// ............... BFS (Kahn's Algorithm – Topological Sort)................
// I used BFS with Kahn's Algorithm to simulate taking courses in order.
// I calculate the in-degree (number of prerequisites) for each course.
// I start with courses that have no prerequisites (in-degree 0) and keep removing them from the graph. If I’m able to remove all courses, there's no cycle.
// If some courses are left, it means there was a cycle blocking progress
//  Time Complexity: O(V + E) — Traverse each course and each edge once.
// Space Complexity: O(V + E) — For the adjacency list and queue.

class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int v = numCourses;
        vector<bool> vis(v, false); // Visited array
        vector<bool> rec(v, false); // Recursion stack array

        // Run DFS for each unvisited node
        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                if (isCycle(i, vis, rec, prerequisites)) {
                    return false; // If a cycle is found, cannot finish courses
                }
            }
        }
        return true; // No cycles → possible to finish all courses
    }
    // Helper function to check for cycle using DFS
    bool isCycle(int src, vector<bool>& vis, vector<bool>& rec, vector<vector<int>>& prerequisites) {
        vis[src] = true;  // Mark the current node as visited
        rec[src] = true;  // Add it to the recursion stack

        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1]; // from node (actual course to take)
            int v = prerequisites[i][0]; // to node (prerequisite to take above course)
            
            if (u == src) {  // Check outgoing edges from current node
                if (!vis[v]) { // we will only process if not visited 
                    if (isCycle(v, vis, rec, prerequisites)) {
                        return true;  // Found a cycle in DFS 
                    }
                } else if (rec[v]) { // if current v is alraedy in recursion stack 
                    return true;  // Found a back edge → cycle
                }
            }
        }

        rec[src] = false;  // Backtrack: remove from recursion stack
        return false;      // No cycle found from this node
    }

};