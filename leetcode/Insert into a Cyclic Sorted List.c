/*
 * Given a node from a cyclic linked list which has been sorted,
 * write a function to insert a value into the list such that it
 * remains a cyclic sorted list. The given node can be any single
 * node in the list.
 *
 * case 1)
 *   prev→val ≤ x ≤ current→val:
 *     Insert between prev and current.
 * case 2)
 *   x is the maximum or minimum value in the list:
 *     Insert before the head.
 *     (ie, the head has the smallest value and its prev→val > head→val).
 * case 3)
 *   Traverses back to the starting point:
 *     Insert before the starting point.
 */
void insert(Node* &aNode, int x) {
    if (!aNode) {
        aNode = new Node(x);
        aNode->next = aNode;
        return;
    }

    Node *prev = Null;
    Node *p = aNode;
    do {
        prev = p;
        p = p->next;

        // For case 1)
        if (prev->val <= x && x <= p->val) break;
        // For case 2)
        if ((prev->val > p->val) && (prev->val <= x || x <= p->val)) break;
    } while (p != aNode);   // when back to starting point, then stop. For case 3)

    Node *node = new Node();
    node->next = p;
    prev->next = node;
}

        
