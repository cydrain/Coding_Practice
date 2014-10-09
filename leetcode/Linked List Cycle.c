// Linked List Cycle
//
// Given a linked list, determine if it has a cycle in it.
//
// Follow up:
// Can you solve it without using extra space? 

    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode *fast, *slow;
        
        fast = slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return true;
        }
        
        return false;
    }
