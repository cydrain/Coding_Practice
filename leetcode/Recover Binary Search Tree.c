/*
 * Recover Binary Search Tree
 *
 * Two elements of a binary search tree (BST) are swapped by mistake.
 *
 * Recover the tree without changing its structure.
 *
 * Note:
 * A solution using O(n) space is pretty straight forward. Could you
 * devise a constant space solution? 
 *
 */

    void inOrder(TreeNode *root, TreeNode* &prev, TreeNode* &e1, TreeNode* &e2) {
        if (!root) return;
        inOrder(root->left, prev, e1, e2);
        if (prev && prev->val > root->val) {
            if (!e1) {
                e1 = prev;
            }
            e2 = root;
        }
        prev = root;
        inOrder(root->right, prev, e1, e2);
    }
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode *prev = NULL, *e1 = NULL, *e2 = NULL;
        inOrder(root, prev, e1, e2);
        swap(e1->val, e2->val);
    }
