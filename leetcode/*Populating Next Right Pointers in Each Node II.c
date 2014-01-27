/*
 * Populating Next Right Pointers in Each Node II
 *
 * Follow up for problem "Populating Next Right Pointers in Each Node".
 *
 * What if the given tree could be any binary tree? Would your previous
 * solution still work?
 *
 * Note:
 *  You may only use constant extra space.
 *
 * For example,
 * Given the following binary tree,
 *
 *          1
 *         /  \
 *        2    3
 *       / \    \
 *      4   5    7
 *
 * After calling your function, the tree should look like:
 *
 *          1 -> NULL
 *         /  \
 *        2 -> 3 -> NULL
 *       / \    \
 *      4-> 5 -> 7 -> NULL
 *      
 */

    TreeLinkNode* findNext(TreeLinkNode *root, bool includeRight) {
        if (includeRight && root->right) {
            return root->right;
        }
        while (root->next) {
            root = root->next;
            if (root->left) return root->left;
            else if (root->right) return root->right;
        }
        return NULL;
    }
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root || (!root->left && !root->right)) return;
        if (root->right) {
            root->right->next = findNext(root, false);
        }
        if (root->left) {
            root->left->next = findNext(root, true);
        }
        
        connect(root->right);
        connect(root->left);
    }


    // solution 2
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        while (root) {
            TreeLinkNode *nextLevel = NULL;
            TreeLinkNode *prev = NULL;
            for ( ; root; root = root->next) {
                if (!nextLevel) {
                    nextLevel = root->left ? root->left : root->right;
                }
                if (root->left) {
                    if (prev) {
                        prev->next = root->left;
                    }
                    prev = root->left;
                }
                if (root->right) {
                    if (prev) {
                        prev->next = root->right;
                    }
                    prev = root->right;
                }
            }
            
            root = nextLevel;
        }
    }
