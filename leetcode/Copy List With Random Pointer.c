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
    

    // go through this list just once
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        map<RandomListNode*, RandomListNode*> m;
        RandomListNode* node = head, *nodeCopy;
        
        nodeCopy = new RandomListNode(head->label);
        m[head] = nodeCopy;
        for (node = head; node; node = node->next) {
            nodeCopy = m[node];
            if (node->next) {
                nodeCopy->next = new RandomListNode(node->next->label);
                m[node->next] = nodeCopy->next;
            }
            if (node->random) {
                if (m.find(node->random) != m.end()) {
                    nodeCopy->random = m[node->random];
                }
                else {
                    nodeCopy->random = new RandomListNode(node->random->label);
                    m[node->random] = nodeCopy->random;
                }
            }
        }

        return m[head];
    }

