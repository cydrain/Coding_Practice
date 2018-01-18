/*
 * Equal Tree Partition

Given a binary tree with n nodes, your task is to check if it's possible to partition the tree to two trees which have the equal sum of values after removing exactly one edge on the original tree.

Example 1:

Input:     
    5
   / \
  10 10
    /  \
   2   3

Output: True
Explanation: 
    5
   / 
  10
      
Sum: 15

   10
  /  \
 2    3

Sum: 15

Example 2:

Input:     
    1
   / \
  2  10
    /  \
   2   20

Output: False
Explanation: You can't split the tree into two trees with equal sum after removing exactly one edge on the tree.
 */
class Solution {
public:
    int checkSubTreeSum(TreeNode* root, unordered_set<int>& s) {
        if (root == nullptr) return 0;
        int lsum = 0, rsum = 0, sum = 0;
        if (root->left) {
            lsum = checkSubTreeSum(root->left, s);
            s.insert(lsum);
            sum += lsum;
        }
        if (root->right) {
            rsum = checkSubTreeSum(root->right, s);
            s.insert(rsum);
            sum += rsum;
        }
        sum += root->val;
        return sum;
    }
    bool checkEqualTree(TreeNode* root) {
        unordered_set<int> s;
        int sum;
        sum = checkSubTreeSum(root, s);
        if (s.empty() || sum % 2) return false;
        return s.count(sum/2);
    }
};
