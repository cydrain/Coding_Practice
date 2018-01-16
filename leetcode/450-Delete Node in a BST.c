/*
 * Delete Node in a BST

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

    Search for a node to remove.
    If the node is found, delete the node.

Note: Time complexity should be O(height of tree).

Example:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7
 */
class Solution {
public:
    TreeNode* findMin(TreeNode* root) {
        while (root->left) {
            root = root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == nullptr) {
                TreeNode* right = root->right;
                delete root;
                return right;
            } else if (root->right == nullptr) {
                TreeNode* left = root->left;
                delete root;
                return left;
            } else {
                TreeNode* minNode = findMin(root->right);
                swap(root->val, minNode->val);
                root->right = deleteNode(root->right, key);
            }
        }
        return root;
    }
};
