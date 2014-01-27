/*
 * Rotate List
 *
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 *
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
 *
 */

    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head) return head;
        ListNode *tail = head, *prev = NULL, *curr = head;
        int n = 1;
        // let 'tail' point to the last node in the list
        while (tail->next) {
            n++;
            tail = tail->next;
        }
        k = k % n;
        // need not rotate
        if (k == 0) return head;
        k = n - k;
        
        while (k--) {
            prev = curr;
            curr = curr->next;
        }
        
        tail->next = head;
        prev->next = NULL;
        
        return curr;
    }
