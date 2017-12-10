/*
 * Partition List
 *
 * Given a linked list and a value x, partition it such that all nodes
 * less than x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each
 * of the two partitions.
 *
 * For example,
 *  Given 1->4->3->2->5->2 and x = 3,
 *  return 1->2->2->4->3->5. 
 *
 */

/* C solution */
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head || !head->next) return head;
        // for ListNode whose val smaller than x
        ListNode *l_head = NULL, *l_tail = NULL;
        // for ListNode whose val equal or greater than x
        ListNode *r_head = NULL, *r_tail = NULL;
        ListNode *node = NULL;
        
        while (head) {
            node = head;
            head = head->next;
            node->next = NULL;
            // link this node to the l-list
            if (node->val < x) {
                if (!l_head) {
                    l_head = l_tail = node;
                }
                else {
                    l_tail->next = node;
                    l_tail = node;
                }
            }
            // otherwise link this node to the r-list
            else {
                if (!r_head) {
                    r_head = r_tail = node;
                }
                else {
                    r_tail->next = node;
                    r_tail = node;
                }
            }
        }
        if (!l_head) {
            return r_head;
        }
        else {
            l_tail->next = r_head;
            return l_head;
        }
    }


/* Java solution */
public class Solution {
    public ListNode partition(ListNode head, int x) {
        if (head == null || head.next == null) return head;
        ListNode lh = null, lt = null, rh = null, rt = null;
        ListNode node = null;
        while (head != null) {
            node = head;
            head = head.next;
            node.next = null;
            
            if (node.val < x) {
                if (lh == null) {
                    lh = lt = node;
                } else {
                    lt.next = node;
                    lt = node;
                }
            } else {
                if (rh == null) {
                    rh = rt = node;
                } else {
                    rt.next = node;
                    rt = node;
                }
            }
        }
        
        if (lh != null) {
            lt.next = rh;
            return lh;
        } else {
            return rh;
        }
    }
}

