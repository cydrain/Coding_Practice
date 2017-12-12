/*
 * Intersection of Two Linked Lists
 *
 * Write a program to find the node at which the intersection of two singly
 * linked lists begins.
 *
 * For example, the following two linked lists:
 *
 * A:          a1 → a2
 *                    ↘
 *                     c1 → c2 → c3
 *                    ↗            
 * B:     b1 → b2 → b3
 *
 * begin to intersect at node c1.
 *
 * Notes:
 *
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode *la = headA, *lb = headB;
        
        while (la && lb) {
            la = la->next;
            lb = lb->next;
        }
        
        if (la == NULL) {
            la = headB;
            while (lb) {
                la = la->next;
                lb = lb->next;
            }
            lb = headA;
        }
        else {
            lb = headA;
            while (la) {
                la = la->next;
                lb = lb->next;
            }
            la = headB;
        }
        
        while (la && lb) {
            if (la == lb) {
                return la;
            }
            la = la->next;
            lb = lb->next;
        }
        return NULL;
    }