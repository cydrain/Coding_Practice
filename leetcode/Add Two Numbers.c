/*
 * Add Two Numbers
 *
 * You are given two linked lists representing two non-negative numbers.
 * The digits are stored in reverse order and each of their nodes contain
 * a single digit. Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 *
 */

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sum, carry = 0;
        int v1, v2;
        ListNode *head = NULL, *tail = NULL, *node;
        while (l1 || l2 || carry) {
            v1 = (l1) ? l1->val : 0;
            v2 = (l2) ? l2->val : 0;
            sum = v1 + v2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            node = new ListNode(sum);
            if (!head) {
                head = node;
                tail = node;
            }
            else {
                tail->next = node;
                tail = node;
            }
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return head;
    }
