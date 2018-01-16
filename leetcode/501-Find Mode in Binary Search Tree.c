/*
 * Find Mode in Binary Search Tree

Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than or equal to the node's key.
    The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
    Both the left and right subtrees must also be binary search trees.

For example:
Given BST [1,null,2,2],

   1
    \
     2
    /
   2

return [2]. 
 */
class Solution {
public:
    TreeNode* prev = nullptr;
    int maxcnt = 0;
    int cnt = 0;
    void inOrder(TreeNode* root, vector<int>& res) {
        if (root == nullptr) return;
        inOrder(root->left, res);
        if (prev != nullptr && root->val == prev->val) {
            cnt++;
        } else {
            cnt = 1;
        }
        if (cnt > maxcnt) {
            maxcnt = cnt;
            res.clear();
            res.push_back(root->val);
        } else if (cnt == maxcnt) {
            res.push_back(root->val);
        }
        prev = root;
        inOrder(root->right, res);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        inOrder(root, ans);
        return ans;
    }
};
