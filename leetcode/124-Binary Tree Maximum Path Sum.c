/*
 * Binary Tree Maximum Path Sum
 *
 * Given a binary tree, find the maximum path sum.
 *
 * The path may start and end at any node in the tree.
 *
 * For example:
 * Given the below binary tree,
 *
 *        1
 *       / \
 *      2   3
 *
 * Return 6. 
 *
 */

int maxPathSumHelper(TreeNode *root, int &maxSum) {
    if (!root) return 0;
    int sum;
    int lsum, rsum;
    lsum = maxPathSumHelper(root->left, maxSum);
    rsum = maxPathSumHelper(root->right, maxSum);
    sum = max(root->val, max(root->val+lsum, root->val+rsum));
    maxSum = max(maxSum, max(root->val+lsum+rsum, sum));
    return sum;
}
int maxPathSum(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int maxSum = INT_MIN;
    maxPathSumHelper(root, maxSum);
    return maxSum;
}
