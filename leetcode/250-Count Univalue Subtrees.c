/*
 * Count Univalue Subtrees
 *
 * Given a binary tree, count the number of uni-value subtrees.
 *
 * A Uni-value subtree means all nodes of the subtree have the same value.
 *
 * For example:
 * Given binary tree,
 *
 *             5
 *            / \
 *           1   5
 *          / \   \
 *         5   5   5
 *
 * return 4. 
 */
class Solution {
public:
    bool countUnivalSubtrees(TreeNode* root, int& count) {
        if (root == nullptr) return true;
        bool lt = countUnivalSubtrees(root->left, count);
        bool rt = countUnivalSubtrees(root->right, count);
        if (lt && rt && (root->left == nullptr || root->left->val == root->val)
                     && (root->right == nullptr || root->right->val == root->val)) {
            count++;
            return true;
        }
        return false;
    }
    int countUnivalSubtrees(TreeNode* root) {
        int count = 0;
        countUnivalSubtrees(root, count);
        return count;
    }
};
