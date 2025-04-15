/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //  Brute Force Approach
// \U0001f539 Idea:
// Do a DFS traversal from the root.

// For each node, calculate the distance to the target node.

// If distance == k, add it to the result.

// \U0001f538 Problems:
// Recomputing distances multiple times → Inefficient.

// Time complexity can be O(N^2) in the worst case.





//Optimized Approach (BFS + Parent Tracking)
// \U0001f539 Idea:
// Convert the binary tree into an undirected graph:

// Store each node’s parent using DFS.

// BFS starting from target node:

// Visit nodes in levels (level = distance from target).

// When we reach distance k, collect all nodes at that level.

// \U0001f4a1 Why this is better:
// Only need to traverse each node once.

// Works efficiently even when going upwards (using parent pointers).
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parentMap;

    void dfs(TreeNode* node, TreeNode* parent) {
        if (!node) return;
        parentMap[node] = parent;
        dfs(node->left, node);
        dfs(node->right, node);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Step 1: Map every node to its parent
        dfs(root, nullptr);

        // Step 2: BFS from target
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        int currDist = 0;

        while (!q.empty()) {
            int size = q.size();
            if (currDist == k) break;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); q.pop();

                // Check all 3 neighbors: left, right, parent
                if (node->left && !visited.count(node->left)) {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if (node->right && !visited.count(node->right)) {
                    q.push(node->right);
                    visited.insert(node->right);
                }
                TreeNode* par = parentMap[node];
                if (par && !visited.count(par)) {
                    q.push(par);
                    visited.insert(par);
                }
            }

            currDist++;
        }

        // Collect all node values at distance k
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }
};
