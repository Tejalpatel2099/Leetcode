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
        ListNode *dummy = new ListNode(); 
        ListNode *temp = dummy; 
        int carry = 0;
        while( (l1 != NULL || l2 != NULL) || carry) {
            int sum = 0; 
            if(l1 != NULL) {    // l1 is not NULL (still has digits left).
         
                sum = sum + l1->val;   // If l1 is not NULL then add its value to  sum and move to next node in l1 

                l1 = l1 -> next; 
            }
            
            if(l2 != NULL) {      //  l2 is not NULL (still has digits left).

                sum = sum + l2 -> val; // if l2is not Null then add its value to sum and move to next node in l2 

                l2 = l2 -> next; 
            }
            
            sum = sum + carry; //Add the previous carry value to sum. and update carry for next iteration 

            carry = sum / 10; 

            ListNode *node = new ListNode(sum % 10);  // craeting new node and attach to result 
            temp -> next = node; 
            temp = temp -> next; 
        }
        return dummy -> next;  // dummy-> next is head of LL  
    }
};