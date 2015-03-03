/*
 * Validate Binary Search Tree
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 *  The left subtree of a node contains only nodes with keys less than the node's key.
 *  The right subtree of a node contains only nodes with keys greater than the node's key.
 *  Both the left and right subtrees must also be binary search trees.
 *
 */

/* C solution */
    bool isValidBST(TreeNode *root, int minval, int maxval) {
        if (!root) return true;
        return (root->val > minval && root->val < maxval &&
                isValidBST(root->left, minval, root->val) &&
                isValidBST(root->right, root->val, maxval));
    }
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return isValidBST(root, INT_MIN, INT_MAX);
    }


/* Java solution */
public class Solution {
    public void inOrderTraversal(TreeNode root, List<Integer> v) {
        if (root == null) return;
        inOrderTraversal(root.left, v);
        v.add(root.val);
        inOrderTraversal(root.right, v);
    }
    public boolean isValidBST(TreeNode root) {
        List<Integer> v = new ArrayList<>();
        inOrderTraversal(root, v);
        for (int i = 1; i < v.size(); i++) {
            if (v.get(i-1) >= v.get(i)) {
                return false;
            }
        }
        return true;
    }
}

