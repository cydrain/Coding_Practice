/*
 * Maximum Depth of Binary Tree
 *
 * Given a binary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path
 * from the root node down to the farthest leaf node.
 *
 */

/* C solution */
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }


/* Java solution */
public class Solution {
    public int maxDepth(TreeNode root) {
        if (root == null) return 0;
        return (1 + Math.max(maxDepth(root.left), maxDepth(root.right)));
    }
}

