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

 //Can either list be empty?
 // Should the result also be a sorted linked list in ascending order?
 // Are duplicate values allowed?
 
 //.........BRUTE .............
 // I will traverse the lsit and collect all node alues in array and then sort the array and cretae a new linke dlist from sorted array 
 // tc :- O(N log N) — due to sorting the array.
 // sc:-  O(N) — for storing values in an array and building a new list.

 // Optimized Approach (Two Pointer Technique – Merge in-place)
// Idea:// Use two pointers to traverse list1 and list2.
// Compare the current nodes of both lists.
// Append the smaller node to the result list.
// Move the pointer of the list from which the node was taken.
// O(N + M), where N and M are lengths of the two lists.
// O(1) (only a few pointers used; in-place merge).

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }

        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};