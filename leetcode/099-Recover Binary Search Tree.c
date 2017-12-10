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

/* C solution */
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


/* Java solution */
public class Solution {
    public void recoverTreeHelper(TreeNode root, List<TreeNode> prev, List<TreeNode> e) {
        if (root == null) return;
        recoverTreeHelper(root.left, prev, e);
        if (prev.get(0) != null && prev.get(0).val > root.val) {
            if (e.get(0) == null) {
                e.set(0, prev.get(0));
            }
            e.set(1, root);
        }
        prev.set(0, root);
        recoverTreeHelper(root.right, prev, e);
    }
    public void recoverTree(TreeNode root) {
        List<TreeNode> e = new ArrayList<>();
        e.add(null);
        e.add(null);
        List<TreeNode> prev = new ArrayList<>();
        prev.add(null);
        recoverTreeHelper(root, prev, e);
        if (e.get(0) != null && e.get(1) != null) {
            int tmp = e.get(0).val;
            e.get(0).val = e.get(1).val;
            e.get(1).val = tmp;
        }
    }
}

