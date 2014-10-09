/*
 * Balanced Binary Tree
 *
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as a
 * binary tree in which the depth of the two subtrees of every node
 * never differ by more than 1. 
 *
 */

    int depth(TreeNode *root) {
        if (!root) return 0;
        return (1 + max(depth(root->left), depth(root->right)));
    }
    
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return true;
        
        int ldepth, rdepth;
        ldepth = depth(root->left);
        rdepth = depth(root->right);
        if (abs(ldepth-rdepth) > 1) return false;
        
        return (isBalanced(root->left) && isBalanced(root->right));
    }




    bool isBalanced(TreeNode *root, int &h) {
        if (!root) {
            h = 0;
            return true;
        }
        int lh, rh;
        bool lb, rb;
        lb = isBalanced(root->left, lh);
        rb = isBalanced(root->right, rh);
        h = max(lh, rh) + 1;
        return (lb && rb && abs(lh-rh) <= 1);
    }
    bool isBalanced(TreeNode *root) {
        int h;
        return isBalanced(root, h);
    }

