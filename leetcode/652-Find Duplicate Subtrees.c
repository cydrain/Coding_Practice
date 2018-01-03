/*
 * Find Duplicate Subtrees
 *
 * Given a binary tree, return all duplicate subtrees. For each kind of duplicate
 * subtrees, you only need to return the root node of any one of them.
 *
 * Two trees are duplicate if they have the same structure with same node values.
 *
 * Example 1: 
 *         1
 *        / \
 *       2   3
 *      /   / \
 *     4   2   4
 *        /
 *       4
 *
 * The following are two duplicate subtrees:
 *       2
 *      /
 *     4
 *  and
 *       4
 */
class Solution {
public:
    string serializeSubtrees(TreeNode* root, unordered_map<string,int>& m, vector<TreeNode*>& ans) {
        if (root == nullptr) return "#";
        string token = to_string(root->val) + "," + serializeSubtrees(root->left, m, ans)
                                            + "," + serializeSubtrees(root->right, m, ans);
        if (m.find(token) == m.end()) {
            m[token] = 1;
        } else {
            m[token]++;
        }
        if (m[token] == 2) ans.push_back(root);
        return token;
    }
        
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> m;
        vector<TreeNode*> ans;
        serializeSubtrees(root, m, ans);
        return ans;
    }
};
