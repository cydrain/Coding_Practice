/*
 * Same Tree
 *
 * Given two binary trees, write a function to check if they are equal or not.
 *
 * Two binary trees are considered equal if they are structurally identical and
 * the nodes have the same value. 
 *
 */

    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!p && !q) return true;
        if ((p && !q) || (!p && q)) return false;
        return ((p->val == q->val) && 
                isSameTree(p->left, q->left) &&
                isSameTree(p->right, q->right));
    }



    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        queue<TreeNode*> queue_p, queue_q;
        TreeNode *n1, *n2;
        queue_p.push(p);
        queue_q.push(q);
        while (!queue_p.empty() && !queue_q.empty()) {
            n1 = queue_p.front(), queue_p.pop();
            n2 = queue_q.front(), queue_q.pop();
            
            if (!n1 && !n2) continue;
            if ((n1 && !n2) || (!n1 && n2)) return false;
            if (n1->val != n2->val) return false;
            
            queue_p.push(n1->left);
            queue_p.push(n1->right);
            queue_q.push(n2->left);
            queue_q.push(n2->right);
        }
        return (queue_p.empty() && queue_q.empty());
    }


/* Java solution */
public class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null) return true;
        if (p == null && q != null) return false;
        if (p != null && q == null) return false;
        if (p.val != q.val) return false;
        return (isSameTree(p.left, q.left) &&
                isSameTree(p.right, q.right));
    }
}

