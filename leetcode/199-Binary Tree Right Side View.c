/*
 * Binary Tree Right Side View
 *
 * Given a binary tree, imagine yourself standing on the right side of it, return
 * the values of the nodes you can see ordered from top to bottom.
 *
 * For example:
 * Given the following binary tree,
 *
 *    1            <---
 *  /   \
 * 2     3         <---
 *  \     \
 *   5     4       <---
 *
 * You should return [1, 3, 4]. 
 */
class Solution {
public:
    void preOrder(TreeNode* root, int level, vector<int>& res) {
        if (!root) return;
        if (level > res.size()) res.push_back(root->val);
        preOrder(root->right, level+1, res);
        preOrder(root->left, level+1, res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        preOrder(root, 1, ans);
        return ans;
    }
};


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return vector<int>();
        vector<int> ans;
        int l1 = 0, l2 = 0, val;
        queue<TreeNode*> q;
        TreeNode *node;
        q.push(root);
        l1++;
        while (!q.empty()) {
            node = q.front(), q.pop();
            l1--;
            val = node->val;
            if (node->left) {
                q.push(node->left);
                l2++;
            }
            if (node->right) {
                q.push(node->right);
                l2++;
            }
            if (l1 == 0) {
                l1 = l2;
                l2 = 0;
                ans.push_back(val);
            }
        }
        return ans;
    }
};
