/*
 Merge two sorted linked lists and return it as a new list.
 The new list should be made by splicing together the nodes of the first two lists.
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *head = NULL, *tail = NULL;
        ListNode *node;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                node = l1;
                l1 = l1->next;
            } else {
                node = l2;
                l2 = l2->next;
            }
            
            node->next = NULL;
            if (!head) {
                head = tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
        }
        tail->next = l1 ? l1 : l2;
        return head;
    }
};


class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *node;
        if (l1->val <= l2->val) {
            node = l1;
            node->next = mergeTwoLists(l1->next, l2);
        }
        else {
            node = l2;
            node->next = mergeTwoLists(l1, l2->next);
        }
        return node;
    }
};
