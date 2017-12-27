/*
 * Binary Tree Longest Consecutive Sequence
 *
 * Given a binary tree, find the length of the longest consecutive sequence path.
 *
 * The path refers to any sequence of nodes from some starting node to any node in
 * the tree along the parent-child connections. The longest consecutive path need
 * to be from parent to child (cannot be the reverse).
 *
 * For example,
 *
 *    1
 *     \
 *      3
 *     / \
 *    2   4
 *         \
 *          5
 * Longest consecutive sequence path is 3-4-5, so return 3. 
 */
class Solution {
public:
    int longestConsecutive(TreeNode* root, int& maxlen) {
        int llen, rlen, currlen = 1;
        if (!root) return 0;
        if (!root->left && !root->right) {
            maxlen = max(maxlen, 1);
            return 1;
        }
        if (root->left) {
            llen = longestConsecutive(root->left, maxlen);
            if (root->val == root->left->val - 1) {
                currlen = max(currlen, llen+1);
            }
        }
        if (root->right) {
            rlen = longestConsecutive(root->right, maxlen);
            if (root->val == root->right->val - 1) {
                currlen = max(currlen, rlen+1);
            }
        }
        maxlen = max(maxlen, currlen);
        return currlen;
    }
    int longestConsecutive(TreeNode* root) {
        int maxlen = 0;
        longestConsecutive(root, maxlen);
        return maxlen;
    }
};
