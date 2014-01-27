/*
 * Symmetric Tree
 *
 * Given a binary tree, check whether it is a mirror of itself 
 * (ie, symmetric around its center).
 *
 * For example, this binary tree is symmetric:
 *     1
 *    / \
 *   2   2
 *  / \ / \
 * 3  4 4  3
 *
 * But the following is not:
 *     1
 *    / \
 *   2   2
 *    \   \
 *     3    3
 *
 * Note:
 * Bonus points if you could solve it both recursively and iteratively. 
 *
 */

// recursive solution
    bool isSymmetric(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if ((p && !q) || (!p && q)) return false;
        return ((p->val == q->val) && 
                isSymmetric(p->left, q->right) &&
                isSymmetric(p->right, q->left));
    }
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return true;
        return (isSymmetric(root->left, root->right));
    }


// iterative solution
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return true;
        
        queue<TreeNode*> lt, rt;
        TreeNode *l, *r;
        
        lt.push(root->left);
        rt.push(root->right);
        while (!lt.empty() && !rt.empty()) {
            l = lt.front(); lt.pop();
            r = rt.front(); rt.pop();
            
            if (!l && !r) continue;
            if (!l || !r) return false;
            if (l->val != r->val) return false;
            
            lt.push(l->left);
            lt.push(l->right);
            
            rt.push(r->right);
            rt.push(r->left);
        }
        
        return (lt.empty() && rt.empty()); 
    }
