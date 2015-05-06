/*
 * Flatten Binary Tree to Linked List
 *
 * Given a binary tree, flatten it to a linked list in-place.
 *
 * For example,
 * Given
 *
 *          1
 *         / \
 *        2   5
 *       / \   \
 *      3   4   6
 *
 * The flattened tree should look like:
 *
 *    1
 *     \
 *      2
 *       \
 *        3
 *         \
 *          4
 *           \
 *            5
 *             \
 *              6
 *
 */

/* C solution */
    void flatten(TreeNode *root, TreeNode* &head) {
        if (!root) return;
        flatten(root->right, head);
        flatten(root->left, head);
        
        root->right = head;
        root->left = NULL;
        head = root;
    }
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode *head = NULL;
        flatten(root, head);
    }


    void flatten(stack<TreeNode *> &s, TreeNode *root) {
        if (!root) return;
        s.push(root);
        flatten(s, root->left);
        flatten(s, root->right);
    }
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<TreeNode *> s;
        flatten(s, root);
        TreeNode *head = NULL, *node = NULL;
        while (!s.empty()) {
            node = s.top();
            s.pop();
            node->left = NULL;
            node->right = head;
            head = node;
        }
    }


    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return;
        
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        
        if (left) {
            root->right = left;
            root->left = NULL;
            
            // link left child's rightmost grand-child to right
            TreeNode *tmp = left;
            while (tmp->right) tmp = tmp->right;
            tmp->right = right;
        }
        
        flatten(root->right);
    }


/* Java solution */
public class Solution {
    public void flatten(TreeNode root, List<TreeNode> list) {
        if (root == null) return;
        TreeNode left = root.left;
        TreeNode right = root.right;
        root.left = null;
        root.right = null;
        list.add(root);
        if (left != null) flatten(left, list);
        if (right != null) flatten(right, list);
    }
    public void flatten(TreeNode root) {
        List<TreeNode> list = new ArrayList<>();
        flatten(root, list);
        for (int i = list.size()-2; i >= 0; i--) {
            list.get(i).right = list.get(i+1);
        }
    }
}

