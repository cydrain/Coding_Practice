/*
 * Construct Binary Tree from Inorder and Postorder Traversal
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree. 
 *
 */

    TreeNode *buildTree(vector<int> &inorder, int in_start, int in_end,
                        vector<int> &postorder, int post_start, int post_end) {
        if (post_start > post_end || in_start > in_end) return NULL;
        int val = postorder[post_end];
        int idx = 0;
        for (idx = 0; idx <= (in_end-in_start); idx++) {
            if (inorder[in_start+idx] == val) break;
        }
        
        TreeNode *root = new TreeNode(val);
        root->left = buildTree(inorder, in_start, in_start+idx-1,
                               postorder, post_start, post_start+idx-1);
        root->right = buildTree(inorder, in_start+idx+1, in_end,
                                postorder, post_start+idx, post_end-1);
        
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return buildTree(inorder, 0, inorder.size()-1,
                         postorder, 0, postorder.size()-1);
    }
