/*
 * Remove Duplicates from Sorted List II
 *
 * Given a sorted linked list, delete all nodes that have duplicate
 * numbers, leaving only distinct numbers from the original list.
 *
 * For example,
 *  Given 1->2->3->3->4->4->5, return 1->2->5.
 *  Given 1->1->1->2->3, return 2->3. 
 *
 */

    // delete all nodes between prev and curr
    void deleteNodes(ListNode* &prev, ListNode* &curr) {
        ListNode *node;
        while (prev->next != curr) {
            node = prev->next;
            prev->next = node->next;
            delete node;
        }
    }
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode *prev = dummy, *curr = head;
        while (curr && curr->next) {
            if (curr->val != curr->next->val) {
                prev = curr;
                curr = curr->next;
            }
            else {
                while (curr && curr->val == prev->next->val) {
                    curr = curr->next;
                }
                deleteNodes(prev, curr);
            }
        }
        
        head = dummy->next;
        delete dummy;
        return head;
    }



    ListNode *deleteDuplicates(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!head || !head->next) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy, *curr = head, *node = curr->next, *tmp;
        while (true) {
            while (node && node->val == curr->val) {
                node = node->next;
            }
            if (curr->next != node) {
                while (curr != node) {
                    tmp = curr;
                    curr = curr->next;
                    prev->next = curr;
                    delete tmp;
                }
            }
            else {
                prev = curr;
                curr = node;
            }
            if (!curr) break;
            node = node->next;
            if (!node) break;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }


/* Java solution */
public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prev = dummy, node = null;
        while (prev.next != null && prev.next.next != null) {
            if (prev.next.val != prev.next.next.val) {
                prev = prev.next;
            } else {
                node = prev.next.next;
                while (node.next != null && node.next.val == prev.next.val) {
                    node = node.next;
                }
                prev.next = node.next;
            }
        }
        return dummy.next;
    }
}

