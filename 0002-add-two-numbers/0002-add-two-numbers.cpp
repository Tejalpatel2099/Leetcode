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

// form new sumlist and this list willbe in reverse order 
// assign dummy node first and also take variable current 
// l1 and l2 and carry variable 
// dummy->next is head  

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;

        while (temp1 != nullptr || temp2 != nullptr) {
            int sum = carry;

            if (temp1) {
                sum += temp1->val;
                temp1 = temp1->next;
            }
            if (temp2) {
                sum += temp2->val;
                temp2 = temp2->next;
            }

            carry = sum / 10;

            ListNode* newNode = new ListNode(sum % 10);
            curr->next = newNode;
            curr = curr->next;
        }

        if (carry) {
            curr->next = new ListNode(carry);
        }

        return dummyHead->next; 
    }
};