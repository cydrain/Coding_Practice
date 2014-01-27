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




    // prev is the ListNode before m-th node, end is the ListNode after n-th node
    void reverseBetween(ListNode *prev, ListNode *end) {
        ListNode *curr = prev->next, *node = curr->next;
        while (node != end) {
            curr->next = node->next;
            node->next = prev->next;
            prev->next = node;
            node = curr->next;
        }
    }
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (m == n) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy, *n_node = head;
        int i;
        for (i = 1; i < m; i++) {
            prev = prev->next;
        }
        for (i = 1; i < n; i++) {
            n_node = n_node->next;
        }
        reverseBetween(prev, n_node->next);
        
        head = dummy->next;
        delete dummy;
        return head;
    }
