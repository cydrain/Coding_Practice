/*
 * Binary Tree Level Order Traversal II
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 *    
 * return its bottom-up level order traversal as:
 *
 * [
 *   [15,7]
 *   [9,20],
 *   [3],
 * ]
 *
 */

    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<TreeNode*> q1, q2;
        vector<vector<int> > r;
        vector<int> level;
        TreeNode *node;
        
        if (!root) return r;
        
        q1.push(root);
        while (!q1.empty()) {
            node = q1.front();
            q1.pop();
            level.push_back(node->val);
            if (node->left) q2.push(node->left);
            if (node->right) q2.push(node->right);
            if (q1.empty()) {
                r.push_back(level);
                level.clear();
                swap(q1, q2);
            }
        }
        
        reverse(r.begin(), r.end());
        return r;
    }
