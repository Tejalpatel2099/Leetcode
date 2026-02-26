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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Edge case: if list is empty or no reversal needed
        if (!head || left == right) {
            return head;
        }

        // Step 1: Create dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // Step 2: Move prev pointer to node before 'left'
        ListNode* prev = dummy;
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // curr will point to first node of reversal section
        ListNode* curr = prev->next;
        
        // Step 3: Reverse nodes between left and right
        for (int i = 0; i < right - left; i++) {
            
            // Store next node
            ListNode* temp = curr->next;
            
            // Move temp node right after prev
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }

        return dummy->next; 
    }
};