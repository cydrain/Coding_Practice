/*
 * Remove Nth Node From End of List
 *
 * Given a linked list, remove the nth node from the end of list and return its head.
 *
 * For example,
 *
 * Given linked list: 1->2->3->4->5, and n = 2.
 *
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 *
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass. 
 *
 */

/* C solution */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy, *tail = dummy, *node;
        for (int i = 0; i < n; i++) {
            tail = tail->next;
        }
        while (tail->next) {
            prev = prev->next;
            tail = tail->next;
        }
        node = prev->next;
        prev->next = node->next;
        delete node;
        
        head = dummy->next;
        delete dummy;
        return head;
    }


/* Java solution */
public class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null) return null;
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode start = dummy, end = dummy;
        int i;
        
        for (i = 0; i < n; i++) {
            end = end.next;
        }
        while (end.next != null) {
            start = start.next;
            end = end.next;
        }
        start.next = start.next.next;
        return dummy.next;
    }
}

