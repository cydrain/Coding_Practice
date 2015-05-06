/*
 * Convert Sorted Array to Binary Search Tree
 *
 * Given an array where elements are sorted in ascending order, convert
 * it to a height balanced BST.
 *
 */

/* C solution */
    TreeNode *sortedArrayToBST(vector<int> &num, int start, int end) {        
        if (start > end) return NULL;
        int m = (start + end) / 2;
        TreeNode *root = new TreeNode(num[m]);
        root->left = sortedArrayToBST(num, start, m-1);
        root->right = sortedArrayToBST(num, m+1, end);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return sortedArrayToBST(num, 0, num.size()-1);
    }


/* Java solution */
public class Solution {
    public TreeNode sortedArrayToBST(int[] num, int start, int end) {
        if (start > end) return null;
        int mid = start + (end-start)/2;
        TreeNode root = new TreeNode(num[mid]);
        root.left = sortedArrayToBST(num, start, mid-1);
        root.right = sortedArrayToBST(num, mid+1, end);
        return root;
    }
    public TreeNode sortedArrayToBST(int[] num) {
        return sortedArrayToBST(num, 0, num.length-1);
    }
}

