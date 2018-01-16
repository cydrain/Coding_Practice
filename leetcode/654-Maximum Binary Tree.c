/*
 * Maximum Binary Tree

Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

    The root is the maximum number in the array.
    The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
    The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.

Construct the maximum tree by the given array and output the root node of this tree.

Example 1:

Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
 */ 
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums, int start, int end) {
        if (start > end) return nullptr;
        TreeNode* node;
        int i, idx = start;
        for (i = start+1; i <= end; i++) {
            if (nums[i] > nums[idx]) {
                idx = i;
            }
        }
        node = new TreeNode(nums[idx]);
        node->left = constructMaximumBinaryTree(nums, start, idx-1);
        node->right = constructMaximumBinaryTree(nums, idx+1, end);
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTree(nums, 0, nums.size()-1);
    }
};
