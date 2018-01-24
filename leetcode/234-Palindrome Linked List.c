/*
 * Palindrome Linked List
 *
 * Given a singly linked list, determine if it is a palindrome.
 *
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 */
class Solution {
public:
    bool isPalindrome(ListNode* &h1, ListNode* h2) {
        if (h2 == nullptr) return true;
        if (isPalindrome(h1, h2->next) && h1->val == h2->val) {
            h1 = h1->next;
            return true;
        } else {
            return false;
        }
    }
    bool isPalindrome(ListNode* head) {
        return isPalindrome(head, head);
    }
};
