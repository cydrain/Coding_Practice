/*
 * Sort List
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 */

ListNode *mergeSort(ListNode *head) {
    if (!head || !head->next) return head;
    ListNode *fast, *slow;
    ListNode *ll, *rl;
    fast = slow = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    ll = head;
    rl = slow->next;
    slow->next = NULL;
    ll = mergeSort(ll);
    rl = mergeSort(rl);
    return merge(ll, rl);
}
ListNode *merge(ListNode *l1, ListNode *l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    ListNode *dummy = new ListNode(0);
    ListNode *tail = dummy;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        }
        else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
        tail->next = NULL;
    }
    if (!l1) {
        tail->next = l2;
    }
    else {
        tail->next = l1;
    }
    tail = dummy->next;
    delete dummy;
    return tail;
}
ListNode *sortList(ListNode *head) {
    return mergeSort(head);
}

