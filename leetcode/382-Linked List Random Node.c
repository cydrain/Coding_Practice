/*
 * Linked List Random Node

Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Follow up:
What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?

Example:

// Init a singly linked list [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
solution.getRandom();
 */
class Solution {
private:
    int count;
    ListNode *head;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        int n = 0;
        ListNode *node = head;
        while (node != nullptr) {
            n++;
            node = node->next;
        }
        count = n;
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int n = rand() % count;
        ListNode *node = head;
        while (n--) node = node->next;
        return node->val;
    }
};
