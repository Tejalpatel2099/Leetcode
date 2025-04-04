/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap based on ListNode values
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<>> pq;

        // Push the head of each list into the priority queue
        for (ListNode* list : lists) {
            if (list) {
                pq.push({list->val, list});
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (!pq.empty()) {
            auto [val, node] = pq.top();
            pq.pop();

            temp->next = node;
            temp = temp->next;

            if (node->next) {
                pq.push({node->next->val, node->next});
            }
        }

        return dummy->next;
    }
};
