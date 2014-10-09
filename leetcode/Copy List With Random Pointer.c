/*
 * Copy List with Random Pointer
 *
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 *
 * Return a deep copy of the list. 
 *
 */

    RandomListNode *copyRandomList(RandomListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (!head) return NULL;
        map<RandomListNode*,RandomListNode*> m;
        RandomListNode *node = head, *node_copy;
        for (node = head; node != NULL; node = node->next) {
            node_copy = new RandomListNode(node->label);
            m[node] = node_copy;
        }
        for (node = head; node != NULL; node = node->next) {
            node_copy = m[node];
            if (node->random) {
                node_copy->random = m[node->random];
            }
            if (node->next) {
                node_copy->next = m[node->next];
            }
        }
        return m[head];
    }
    
