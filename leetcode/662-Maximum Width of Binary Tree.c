/*
Maximum Width of Binary Tree

Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:

Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).

Example 2:

Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).

Example 3:

Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).

Example 4:

Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).

 */ 
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<pair<TreeNode*,int>> q;
        TreeNode* node;
        int l1 = 0, l2 = 0, idx, lb = INT_MAX, rb = INT_MIN, width = 0;
        q.emplace(root, 0);
        l1++;
        while (!q.empty()) {
            node = q.front().first;
            idx = q.front().second;
            q.pop();
            l1--;
            lb = min(lb, idx);
            rb = max(rb, idx);
            if (node->left) {
                q.emplace(node->left, 2*idx);
                l2++;
            }
            if (node->right) {
                q.emplace(node->right, 2*idx+1);
                l2++;
            }
            if (l1 == 0) {
                l1 = l2;
                l2 = 0;
                width = max(width, rb-lb+1);
                lb = INT_MAX;
                rb = INT_MIN;
            }
        } 
        return width;
    }
};
