/*
 * Reverse Linked List II
 *
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 *
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 *
 * return 1->4->3->2->5->NULL.
 *
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list. 
 *
 */

    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy, *curr = head, *node = NULL;
        int i;
        for (i = 1; i < m; i++) {
            if (curr == NULL) return NULL;
            prev = curr;
            curr = curr->next;
        }
        for ( ; i < n; i++) {
            node = curr->next;
            if (node == NULL) return NULL;
            curr->next = node->next;
            node->next = prev->next;
            prev->next = node;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }




    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (!head || !head->next || m == n) return head;
        ListNode *dummy = new ListNode(0);
        ListNode *prev, *curr, *node;
        int i = 0;
        
        dummy->next = head;
        prev = dummy;
        
        for (i = 1; i < m; i++) {
            prev = prev->next;
        }
        
        curr = prev->next;
        for (i = m; i < n; i++) {
            node = curr->next;
            curr->next = node->next;
            node->next = prev->next;
            prev->next = node;
        }
        
        head = dummy->next;
        delete dummy;
        return head;
    }

