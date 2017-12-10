/*
 * Binary Tree Zigzag Level Order Traversal
 *
 * Given a binary tree, return the zigzag level order traversal of
 * its nodes' values. (ie, from left to right, then right to left
 * for the next level and alternate between).
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
 * return its zigzag level order traversal as:
 *
 * [
 *   [3],
 *   [20,9],
 *   [15,7]
 * ]
 * 
 */

/* C solution */
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > r;
        vector<int> level;
        queue<TreeNode*> curr, next;
        TreeNode *node;
        int dir = 1;
        
        if (!root) return r;
        
        curr.push(root);
        while (!curr.empty()) {
            node = curr.front();
            curr.pop();
            level.push_back(node->val);
            if (node->left) next.push(node->left);
            if (node->right) next.push(node->right);
            if (curr.empty()) {
                if (dir == -1) {
                    reverse(level.begin(), level.end());
                }
                dir *= -1;
                r.push_back(level);
                level.clear();
                swap(curr, next);
            }
        }
        
        return r;
    }


    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > r;
        if (!root) return r;
        vector<int> p;
        TreeNode *node;
        queue<TreeNode*> q;
        int level1 = 0, level2 = 0;
        bool left_to_right = true;
        
        q.push(root);
        level1++;
        while (!q.empty()) {
            node = q.front();
            q.pop();
            level1--;
            p.push_back(node->val);
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
                if (!left_to_right) {
                    reverse(p.begin(), p.end());
                }
                left_to_right = !left_to_right;
                r.push_back(p);
                p.clear();
            }
        }
        
        return r;
    }


/* Java solution */
public class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> r = new ArrayList<>();
        if (root == null) return r;
        Queue<TreeNode> q = new LinkedList<>();
        List<Integer> list = new ArrayList<>();
        TreeNode node = null;
        int level1 = 0, level2 = 0;
        boolean needRev = false;
        
        q.offer(root);
        level1++;
        while (q.size() != 0) {
            node = q.poll();
            level1--;
            list.add(node.val);
            
            if (node.left != null) {
                q.offer(node.left);
                level2++;
            }
            if (node.right != null) {
                q.offer(node.right);
                level2++;
            }
            if (level1 == 0) {
                level1 = level2;
                level2 = 0;
                if (needRev) {
                    Collections.reverse(list);
                }
                needRev = !needRev;
                r.add(list);
                list = new ArrayList<Integer>();
            }
        }
        return r;
    }
}

