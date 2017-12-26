/*
 * Closest Binary Search Tree Value
 *
 * Given a non-empty binary search tree and a target value, find the value in
 * the BST that is closest to the target. 
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int rv = root->val;
        TreeNode* kid = (target < rv ? root->left : root->right);
        if (!kid) return rv;
        int kv = closestValue(kid, target);
        return (abs(kv-target) < abs(rv-target) ? kv : rv);
    }
};

