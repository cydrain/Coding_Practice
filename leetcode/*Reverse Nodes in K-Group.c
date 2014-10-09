/*
 * Reverse Nodes in k-Group
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 *
 * If the number of nodes is not a multiple of k then left-out nodes in the
 * end should remain as it is.
 *
 * You may not alter the values in the nodes, only nodes itself may be changed.
 *
 * Only constant memory is allowed.
 *
 * For example,
 * Given this linked list: 1->2->3->4->5
 *
 * For k = 2, you should return: 2->1->4->3->5
 * For k = 3, you should return: 3->2->1->4->5 
 *
 */

    void reverseNodes(ListNode* &prev, ListNode* &curr, ListNode* &end) {
        ListNode* node = curr->next;
        while (node != end) {
            curr->next = node->next;
            node->next = prev->next;
            prev->next = node;
            node = curr->next;
        }
    }
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (k <= 1) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy, *curr = head, *tail;
        int n;
        while (true) {
            for (n = 0, tail = curr; n < k && tail; n++) {
                tail = tail->next;
            }
            if (n != k) break;
            reverseNodes(prev, curr, tail);
            prev = curr;
            curr = tail;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }




    // reverse the nodes between "prev" (not included) and "end" (not included)
    void reverseKGroupHelper(ListNode *prev, ListNode *end) {
        ListNode *first = prev->next, *node;
        for (node = first->next; node != end; node = first->next) {
            first->next = node->next;
            node->next = prev->next;
            prev->next = node;
        }
    }
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head || !head->next) return head;
        if (k == 1) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy, *first, *end;
        int i;
        while (prev != NULL) {
            first = prev->next;
            end = prev;
            for (i = 0; i < k; i++) {
                if (end == NULL) break;
                end = end->next;
            }
            if (i != k || end == NULL) break;
            reverseKGroupHelper(prev, end->next);
            prev = first;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }

