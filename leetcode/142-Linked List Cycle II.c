/*
 * Linked List Cycle II
 *
 * Given a linked list, return the node where the cycle begins.
 * If there is no cycle, return null.
 *
 * Follow up:
 * Can you solve it without using extra space? 
 */

ListNode *detectCycle(ListNode *head) {
    if (!head || !head->next) return NULL;
    ListNode *fast, *slow;
    bool hasCycle = false;
    
    fast = slow = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            hasCycle = true;
            break;
        }
    }
    
    if (hasCycle) {
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
    else {
        return NULL;
    }
}

