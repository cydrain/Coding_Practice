/*
 * Minimum Absolute Difference in BST
 *
 * Given a binary search tree with non-negative values, find the minimum absolute
 * difference between values of any two nodes.
 *
 * Example:
 *
 * Input:
 *
 *   1
 *    \
 *     3
 *    /
 *   2
 *
 * Output: 1
 *
 * Explanation:
 * The minimum absolute difference is 1, which is the difference between 2 and 1
 * (or between 2 and 3).
 */
class Solution {
public:
    void getMinimumDifference(TreeNode* root, TreeNode* &prev, int& minval) {
        if (root == nullptr) return;
        getMinimumDifference(root->left, prev, minval);
        if (prev != nullptr) {
            minval = min(minval, root->val-prev->val);
        }
        prev = root;
        getMinimumDifference(root->right, prev, minval);
    }
    int getMinimumDifference(TreeNode* root) {
        TreeNode* prev = nullptr;
        int minval = INT_MAX;
        getMinimumDifference(root, prev, minval);
        return minval;
    }
};
