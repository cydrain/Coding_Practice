/*
 * Kth Smallest Element in a BST
 *
 * Given a binary search tree, write a function kthSmallest to find the kth
 * smallest element in it.
 */
class Solution {
public:
    void kthSmallest(TreeNode* root, int& k, int& ans) {
        if (!root) return;
        kthSmallest(root->left, k, ans);
        if (--k == 0) {
            ans = root->val;
            return;
        }
        kthSmallest(root->right, k, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        kthSmallest(root, k, ans);
        return ans;
    }
};
