/*
 * Unique Binary Search Trees II
 *
 * Given n, generate all structurally unique BST's (binary search trees)
 * that store values 1...n.
 *
 * For example,
 * Given n = 3, your program should return all 5 unique BST's shown below.
 *
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 *
 */

/* C solution */
    vector<TreeNode *> generateTrees(int start, int end) {
        vector<TreeNode*> result;
        vector<TreeNode*> leftTrees;
        vector<TreeNode*> rightTrees;
        int i, j, k;
        
        if (start > end) {
            result.push_back(NULL);
            return result;
        }
        
        for (i = start; i <= end; i++) {
            leftTrees = generateTrees(start, i-1);
            rightTrees = generateTrees(i+1, end);
            
            for (j = 0; j < leftTrees.size(); j++) {
                for (k = 0; k < rightTrees.size(); k++) {
                    TreeNode *root = new TreeNode(i);
                    root->left = leftTrees[j];
                    root->right = rightTrees[k];
                    result.push_back(root);
                }
            }
        }
        
        return result;
    }
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return generateTrees(1, n);
    }


/* Java solution */
public class Solution {
    public List<TreeNode> generateTreesHelper(int start, int end) {
        List<TreeNode> r = new ArrayList<>();
        if (start > end) {
            r.add(null);
            return r;
        } else {
            int i, j, k;
            for (i = start; i <= end; i++) {
                List<TreeNode> lt = generateTreesHelper(start, i-1);
                List<TreeNode> rt = generateTreesHelper(i+1, end);
                for (j = 0; j < lt.size(); j++) {
                    for (k = 0; k < rt.size(); k++) {
                        TreeNode root = new TreeNode(i);
                        root.left = lt.get(j);
                        root.right = rt.get(k);
                        r.add(root);
                    }
                }
            }
            return r;
        }
    }
    public List<TreeNode> generateTrees(int n) {
        return generateTreesHelper(1, n);
    }
}

