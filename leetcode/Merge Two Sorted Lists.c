/*
 * Merge Two Sorted Lists
 *
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes
 * of the first two lists.
 *
 */

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *dummy = new ListNode(0);
        ListNode *head = NULL, *tail = dummy, *node;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                node = l1;
                l1 = l1->next;
            }
            else {
                node = l2;
                l2 = l2->next;
            }
            node->next = NULL;
            tail->next = node;
            tail = node;
        }
        if (l1) {
            tail->next = l1;
        }
        else {
            tail->next = l2;
        }
        
        head = dummy->next;
        delete dummy;
        return head;
    }




    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *head = NULL;
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) {
            head = l1;
            head->next = mergeTwoLists(l1->next, l2);
        }
        else {
            head = l2;
            head->next = mergeTwoLists(l1, l2->next);
        }
        return head;
    }
