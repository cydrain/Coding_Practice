/*
 * Inorder Successor in BST
 *
 * Given a binary search tree and a node in it, find the in-order successor of
 * that node in the BST.
 *
 * Note: If the given node has no in-order successor in the tree, return null. 
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *node = root, *ans = nullptr;
        while (node != nullptr) {
            if (node->val > p->val) {
                ans = node;
                node = node->left;
            } else {
                node = node->right;
            }
        }
        return ans;
    }
};
