/*
 * Merge k Sorted Lists
 *
 * Merge k sorted linked lists and return it as one sorted list.
 * Analyze and describe its complexity. 
 *
 */

    ListNode *merge2Lists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *head = NULL;
        if (l1->val < l2->val) {
            head = l1;
            head->next = merge2Lists(l1->next, l2);
        }
        else {
            head = l2;
            head->next = merge2Lists(l1, l2->next);
        }
        return head;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *head = NULL;
        for (int i = 0; i < lists.size(); i++) {
            head = merge2Lists(head, lists[i]);
        }
        return head;
    }




    class comp {
        public:
        bool operator()(const ListNode *a, const ListNode *b) {
            return a->val < b->val;
        }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *head = NULL, *tail = NULL;
        ListNode *node;
        multiset<ListNode*,comp> s;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                s.insert(lists[i]);
            }
        }
        while (!s.empty()) {
            node = *(s.begin());
            s.erase(s.begin());
            if (node->next) {
                s.insert(node->next);
            }
            
            if (!head) {
                head = tail = node;
            }
            else {
                tail->next = node;
                tail = node;
            }
        }
        return head;
    }




    ListNode *merge2Lists(ListNode* l1, ListNode *l2) {
        ListNode *head = NULL, *tail = NULL, *node;
        if (!l1) return l2;
        if (!l2) return l1;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                node = l1;
                l1 = l1->next;
            }
            else {
                node = l2;
                l2 = l2->next;
            }
            node->next = NULL;
            
            if (!head) {
                head = tail = node;
            }
            else {
                tail->next = node;
                tail = node;
            }
        }
        
        tail->next = l1 ? l1 : l2;
        
        return head;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *head = NULL;
        int i;
        for (i = 0; i < lists.size(); i++) {
            head = merge2Lists(head, lists[i]);
        }
        return head;
    }

