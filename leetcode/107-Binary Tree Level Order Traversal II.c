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

/* C solution */
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


/* Java solution */
public class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> r = new LinkedList<>();
        if (root == null) return r;
        List<Integer> list = new LinkedList<>();
        ArrayDeque<TreeNode> q = new ArrayDeque<>();
        TreeNode node = null;
        int level1 = 0, level2 = 0;
        q.addLast(root);
        level1++;
        
        while (!q.isEmpty()) {
            node = q.pollFirst();
            level1--;
            list.add(node.val);
            if (node.left != null) {
                q.addLast(node.left);
                level2++;
            }
            if (node.right != null) {
                q.addLast(node.right);
                level2++;
            }
            if (level1 == 0) {
                level1 = level2;
                level2 = 0;
                r.add(0, list);
                list = new LinkedList<Integer>();
            }
        }
        return r;
    }
}

