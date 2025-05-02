// Is the length of the list always a multiple of k?
//-> If not, what should we do with the remaining nodes (less than k) at the
//end?

 // should the reversal happen in-place or can I use extra memory?
    // → Usually, it’s expected to do it in-place.

    // Can I modify the original linked list, or do I need to return a new list?
    // → Usually, you are allowed to modify it and return the new head.

    // We are given a singly linked list and an integer k. We need to reverse
    // the list in groups of size k. If fewer than k nodes remain at the end, we
    // leave them as-is.We use recursion to solve this:

    // First, check if there are at least k nodes left. If not, return the head
    // as-is.

    // If k nodes exist, we recursively reverse the rest of the list first.

    // Then, we reverse the current k nodes and attach them to the result from
    // the recursive call.

    // This way, we handle the list from end to start recursively.

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;

        // Step 1: Check if at least k nodes exist
        while (count < k) {
            if (temp == nullptr) {
                return head; // Not enough nodes left, return as-is
            }
            temp = temp->next;
            count++;
        }

        // Step 2: Recursive call for the rest of the list
        // temp now points to the (k+1)-th node
        ListNode* prevNode = reverseKGroup(temp, k);

        // Step 3: Reverse current k-group
        // We reverse current group and attach prevNode (reversed remainder) at
        // the end
        temp = head;
        count = 0;

        while (count < k) {
            ListNode* next = temp->next; // Save next node
            temp->next = prevNode;       // Reverse the link
            prevNode = temp;             // Move prevNode ahead
            temp = next;                 // Move to next node
            count++;
        }

        // Step 4: Return new head of this reversed group
        return prevNode;
    }
};
