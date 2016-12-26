// Binary Tree Preorder Traversal
//
// Given a binary tree, return the preorder traversal of its nodes' values.
// For example:
// Given binary tree {1,#,2,3},
//
//    1
//     \
//      2
//     /
//    3
//
// return [1,2,3]. 
//
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> r;
        TreeNode *curr, *tmp;
        curr = root;
        while (curr) {
            r.push_back(curr->val);
            if (curr->left) {
                tmp = curr->left;
                while (tmp->right && tmp->right != curr) {
                    tmp = tmp->right;
                }
                if (!tmp->right) {
                    tmp->right = curr;
                    curr = curr->left;
                } else {
                    r.pop_back();
                    tmp->right = NULL;
                    curr = curr->right;
                }
            } else {
                curr = curr->right;
            }
        }
        return r;
    }
};

    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode*> s;
        vector<int> r;
        TreeNode *node;
        if (!root) return r;
        
        s.push(root);
        while (!s.empty()) {
            node = s.top();
            s.pop();
            r.push_back(node->val);
            if (node->right) s.push(node->right);
            if (node->left) s.push(node->left);
        }
        
        return r;
    }

