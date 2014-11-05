/*
 * Binary Tree Inorder Traversal
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 *    1
 *     \
 *      2
 *     /
 *    3
 *
 * return [1,3,2].
 *
 * Note: Recursive solution is trivial, could you do it iteratively?
 *
 */

    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> r;
        TreeNode *node = root, *tmp;
        
        while (node) {
            if (!node->left) {
                r.push_back(node->val);
                node = node->right;
            }
            else {
                tmp = node->left;
                while (tmp->right && tmp->right != node) {
                    tmp = tmp->right;
                }
                if (!tmp->right) {
                    tmp->right = node;
                    node = node->left;
                }
                else {
                    tmp->right = NULL;
                    r.push_back(node->val);
                    node = node->right;
                }
            }
        }
        
        return r;
    }



    void pushLeft(stack<TreeNode*> &s, TreeNode *node) {
        while (node != NULL) {
            s.push(node);
            node = node->left;
        }
    }
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode*> s;
        TreeNode *node;
        vector<int> res;
        if (!root) return res;
        pushLeft(s, root);
        while (!s.empty()) {
            node = s.top();
            s.pop();
            res.push_back(node->val);
            pushLeft(s, node->right);
        }
        return res;
    }

