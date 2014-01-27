/*
 * Minimum Depth of Binary Tree
 *
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along the shortest path from
 * the root node down to the nearest leaf node.
 *
 */

    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        if (root->left && !root->right) return 1+minDepth(root->left);
        if (!root->left && root->right) return 1+minDepth(root->right);
        
        return 1+min(minDepth(root->left), minDepth(root->right));
    }



    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        if (root->left && root->right) {
            return 1 + min(minDepth(root->left), minDepth(root->right));
        }
        else if (root->left) {
            return 1 + minDepth(root->left);
        }
        else {
            return 1 + minDepth(root->right);
        }
    }
