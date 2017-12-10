/*
 * Insertion Sort List
 *
 * Sort a linked list using insertion sort.
 */

void insertionSortList(ListNode* &head, ListNode* &tail, ListNode *node) {
    ListNode *curr;
    if (!head && !tail) {
        head = tail = node;
    }
    else if (node->val <= head->val) {
        node->next = head;
        head = node;
    }
    else if (node->val >= tail->val) {
        tail->next = node;
        tail = node;
    }
    else {
        curr = head;
        while (node->val > curr->next->val) {
            curr = curr->next;
        }
        node->next = curr->next;
        curr->next = node;
    }
}
ListNode *insertionSortList(ListNode *head) {
    if (!head || !head->next) return head;
    ListNode *newHead = NULL, *newTail = NULL;
    ListNode *node;
    while (head) {
        node = head;
        head = head->next;
        node->next = NULL;
        insertionSortList(newHead, newTail, node);
    }
    return newHead;
}

