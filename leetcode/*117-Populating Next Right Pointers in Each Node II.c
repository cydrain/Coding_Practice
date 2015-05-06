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
        if (!root) return;
        TreeLinkNode *curr = root;
        TreeLinkNode *nextLevelHead = NULL, *nextLevelPrev = NULL;
        while (curr) {
            if (curr->left) {
                if (!nextLevelHead) {
                    nextLevelHead = curr->left;
                }
                if (nextLevelPrev) {
                    nextLevelPrev->next = curr->left;
                }
                nextLevelPrev = curr->left;
            }
            if (curr->right) {
                if (!nextLevelHead) {
                    nextLevelHead = curr->right;
                }
                if (nextLevelPrev) {
                    nextLevelPrev->next = curr->right;
                }
                nextLevelPrev = curr->right;
            }
            if (curr->next) {
                curr = curr->next;
            } else {
                curr = nextLevelHead;
                nextLevelHead = NULL;
                nextLevelPrev = NULL;
            }
        }
    }

/* Java solution */
public class Solution {
    public void connect(TreeLinkNode root) {
        TreeLinkNode curr = root;
        TreeLinkNode nextPrev = null, nextHead = null;
        
        while (curr != null) {
            if (curr.left != null) {
                if (nextHead == null) {
                    nextHead = curr.left;
                }
                if (nextPrev != null) {
                    nextPrev.next = curr.left;
                }
                nextPrev = curr.left;
            }
            if (curr.right != null) {
                if (nextHead == null) {
                    nextHead = curr.right;
                }
                if (nextPrev != null) {
                    nextPrev.next = curr.right;
                }
                nextPrev = curr.right;
            }
            if (curr.next != null) {
                curr = curr.next;
            } else {
                curr = nextHead;
                nextHead = null;
                nextPrev = null;
            }
        }
    }
}

