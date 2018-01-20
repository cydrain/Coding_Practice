/*
 * Binary Search Tree Iterator
 *
 * Implement an iterator over a binary search tree (BST). Your iterator will be
 * initialized with the root node of a BST.
 *
 * Calling next() will return the next smallest number in the BST.
 *
 * Note: next() and hasNext() should run in average O(1) time and uses O(h) memory,
 * where h is the height of the tree.
 */
class BSTIterator {
private:
    stack<TreeNode*> s;
    void pushLeft(TreeNode* node) {
        while (node) {
            s.push(node);
            node = node->left;
        }
    }
public:
    BSTIterator(TreeNode *root) {
        pushLeft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (!s.empty());
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* node = s.top();
        s.pop();
        pushLeft(node->right);
        return node->val;
    }
};
