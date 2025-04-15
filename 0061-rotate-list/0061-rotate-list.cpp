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
    ListNode* rotateRight(ListNode* head, int k) {
      if (!head || !head->next || k == 0) return head;

        // Step 1: Count length and find last node (tail)
        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }

        // Step 2: Normalize k
        k = k % len;
        if (k == 0) return head;

        // Step 3: Make it circular
        tail->next = head;

        // Step 4: Find new tail (len - k steps from head)
        ListNode* newTail = head;
        for (int i = 0; i < len - k - 1; ++i) {
            newTail = newTail->next;
        }

        // Step 5: Break the circle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;  
    }
};