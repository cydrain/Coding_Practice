/*
 * Sum Root to Leaf Numbers
 *
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf
 * path could represent a number.
 *
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 *
 * Find the total sum of all root-to-leaf numbers.
 * 
 * For example,
 *
 *     1
 *    / \
 *   2   3
 *
 *  The root-to-leaf path 1->2 represents the number 12.
 *  The root-to-leaf path 1->3 represents the number 13.
 *  Return the sum = 12 + 13 = 25. 
 *
 */

    void sumNumbersHelper(TreeNode *root, int val, int &sum) {
        if (!root) return;
        int tmp = val*10 + root->val;
        if (!root->left && !root->right) {
            sum += tmp;
        }
        else {
            if (root->left) {
                sumNumbersHelper(root->left, tmp, sum);
            }
            if (root->right) {
                sumNumbersHelper(root->right, tmp, sum);
            }
        }
    }
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sum = 0;
        sumNumbersHelper(root, 0, sum);
        return sum;
    }



    int sumNumbersHelper(TreeNode* root, int parentNum) {
        if (!root) return 0;
        int currNum = parentNum*10 + root->val;
        if (!root->left && !root->right) return currNum;
        return sumNumbersHelper(root->left, currNum) +
               sumNumbersHelper(root->right, currNum);
    }
    int sumNumbers(TreeNode *root) {
        return sumNumbersHelper(root, 0);
    }

