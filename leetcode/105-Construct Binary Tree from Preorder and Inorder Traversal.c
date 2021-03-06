/*
 * Construct Binary Tree from Preorder and Inorder Traversal
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree. 
 *
 */

/* C solution */
    TreeNode *buildTree(vector<int> &preorder, int pre_start, int pre_end,
                        vector<int> &inorder, int in_start, int in_end) {
        if (pre_start > pre_end || in_start > in_end) return NULL;
        int val = preorder[pre_start];
        int idx = 0;
        for (idx = 0; idx <= (in_end-in_start); idx++) {
            if (inorder[in_start+idx] == val) break;
        }
        
        TreeNode *root = new TreeNode(val);
        root->left = buildTree(preorder, pre_start+1, pre_start+idx,
                                inorder, in_start, in_start+idx-1);
        root->right = buildTree(preorder, pre_start+idx+1, pre_end,
                                inorder, in_start+idx+1, in_end);
        
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return buildTree(preorder, 0, preorder.size()-1,
                         inorder, 0, inorder.size()-1);
    }


/* Java solution */
public class Solution {
    public TreeNode buildTree(int[] preorder, int pre_start, int pre_end,
                              int[] inorder, int in_start, int in_end) {
        int idx;
        if (pre_start > pre_end || in_start > in_end) {
            return null;
        }
        for (idx = 0; in_start+idx <= in_end; idx++) {
            if (inorder[in_start+idx] == preorder[pre_start]) {
                break;
            }
        }
        TreeNode root = new TreeNode(preorder[pre_start]);
        root.left = buildTree(preorder, pre_start+1, pre_start+idx,
                              inorder, in_start, in_start+idx-1);
        root.right = buildTree(preorder, pre_start+idx+1, pre_end,
                               inorder, in_start+idx+1, in_end);
        return root;
    }
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return buildTree(preorder, 0, preorder.length-1,
                         inorder, 0, inorder.length-1);
    }
}

