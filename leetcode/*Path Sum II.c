/*
 * Path Sum II
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each
 * path's sum equals the given sum.
 *
 * For example:
 * Given the below binary tree and sum = 22,
 *
 *               5
 *              / \
 *             4   8
 *            /   / \
 *           11  13  4
 *          /  \    / \
 *         7    2  5   1
 *
 * return
 * [
 *    [5,4,11,2],
 *    [5,8,4,5]
 * ]
 *
 */

    void getPath(TreeNode *root, int sum, vector<int> &path, vector<vector<int> > &result) {
        if (!root) return;
        
        path.push_back(root->val);
        if (!root->left && !root->right) {
            if (root->val == sum) {
                result.push_back(path);
            }
        }
        else {
            if (root->left)
                getPath(root->left, sum-root->val, path, result);
            if (root->right)
                getPath(root->right, sum-root->val, path, result);
        }
        path.pop_back();
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        vector<int> path;
        getPath(root, sum, path, result);
        return result;
    }
