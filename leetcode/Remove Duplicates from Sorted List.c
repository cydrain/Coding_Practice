/*
 * Remove Duplicates from Sorted List
 *
 * Given a sorted linked list, delete all duplicates such that each
 * element appear only once.
 *
 * For example,
 *  Given 1->1->2, return 1->2.
 *  Given 1->1->2->3->3, return 1->2->3. 
 *
 */

    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *curr = head, *node = NULL;
        while (curr && curr->next) {
            node = curr->next;
            if (curr->val == node->val) {
                curr->next = node->next;
                delete node;
            }
            else {
                curr = node;
            }
        }
        return head;
    }
