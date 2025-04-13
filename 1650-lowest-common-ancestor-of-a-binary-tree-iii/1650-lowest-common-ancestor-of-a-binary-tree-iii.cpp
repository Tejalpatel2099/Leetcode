/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node* q) {
        set<int> pp;
        while (p != nullptr) {
            pp.insert(p->val);
            p = p->parent;
        }
        while (q != nullptr) {
            auto found = pp.find(q->val);
            if (found != pp.end()) {
                return q;
            }
            q = q->parent;
        }
        return p;
    }
};