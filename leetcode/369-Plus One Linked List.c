/*
 * Plus One Linked List
 *
 * Given a non-negative integer represented as non-empty a singly linked list of
 * digits, plus one to the integer.
 *
 * You may assume the integer do not contain any leading zero, except the number 0 itself.
 *
 * The digits are stored such that the most significant digit is at the head of the list.
 *
 * Example:
 *   Input:  1->2->3
 *   Output: 1->2->4
 */
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *lastNotNine, *node = dummy;
        while (node != nullptr) {
            if (node->val != 9) {
                lastNotNine = node;
            }
            node = node->next;
        }
        lastNotNine->val++;
        for (node = lastNotNine->next; node != nullptr; node = node->next) {
            node->val = 0;
        }
        return (dummy->val == 0 ? dummy->next : dummy);
    }
};


class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *first = head, *second;
        while (first->next != nullptr) {
            second = first->next;
            first->next = second->next;
            second->next = head;
            head = second;
        }
        return head;
    }
    ListNode* plusOne(ListNode* head) {
        ListNode *node;
        int sum, carry = 1;
        head = reverse(head);
        node = head;
        while (node != nullptr && carry != 0) {
            sum = node->val + carry;
            carry = sum / 10;
            node->val = sum % 10;
            node = node->next;
        }
        head = reverse(head);
        if (carry) {
            ListNode* newhead = new ListNode(carry);
            newhead->next = head;
            return newhead;
        } else {
            return head;
        }
    }
};
