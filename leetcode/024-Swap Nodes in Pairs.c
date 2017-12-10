/*
 * Swap Nodes in Pairs
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * For example,
 *
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 * Your algorithm should use only constant space. You may not modify the
 * values in the list, only nodes itself can be changed. 
 *
 */

/* C solution */
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *prev = NULL, *curr = head, *node;
        while (curr && curr->next) {
            node = curr->next;
            curr->next = node->next;
            node->next = curr;
            if (prev) {
                prev->next = node;
            }
            else {
                head = node;
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }



    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head || !head->next) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy, *curr, *node;
        while (prev->next && prev->next->next) {
            curr = prev->next;
            node = curr->next;
            
            curr->next = node->next;
            node->next = prev->next;
            prev->next = node;
            
            prev = curr;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }


/* Java solution */
public class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prev = dummy, first = null, second = null;
        
        while (prev.next != null && prev.next.next != null) {
            first = prev.next;
            second = first.next;
            
            first.next = second.next;
            second.next = first;
            prev.next = second;
            
            prev = first;
        }
        
        return dummy.next;
    }
}

