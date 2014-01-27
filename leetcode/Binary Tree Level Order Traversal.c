/*
 * Binary Tree Level Order Traversal
 *
 * Given a binary tree, return the level order traversal of its
 * nodes' values. (ie, from left to right, level by level).
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
 * return its level order traversal as:
 *
 * [
 *   [3],
 *   [9,20],
 *   [15,7]
 * ]
 * 
 */

    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > r;
        vector<int> level;
        queue<TreeNode*> curr, next;
        TreeNode *node;
        
        if (!root) return r;
        
        curr.push(root);
        while (!curr.empty()) {
            node = curr.front();
            curr.pop();
            level.push_back(node->val);
            if (node->left) next.push(node->left);
            if (node->right) next.push(node->right);
            if (curr.empty()) {
                r.push_back(level);
                level.clear();
                swap(curr, next);
            }
        }
        
        return r;
    }





    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > r;
        if (!root) return r;
        
        queue<TreeNode*> q;
        TreeNode *node = NULL;
        int level1 = 0, level2 = 0;
        vector<int> path;
        
        q.push(root);
        level1++;
        while (!q.empty()) {
            node = q.front();
            q.pop();
            level1--;
            path.push_back(node->val);
            if (node->left) {
                q.push(node->left);
                level2++;
            }
            if (node->right) {
                q.push(node->right);
                level2++;
            }
            if (level1 == 0) {
                level1 = level2;
                level2 = 0;
                r.push_back(path);
                path.clear();
            }
        }
        return r;
    }
