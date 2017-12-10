#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r) {
    if (l > r) return NULL;
    int m = l + (r-l)/2;
    TreeNode* root = new TreeNode(nums[m]);
    root->left = sortedArrayToBST(nums, l, m-1);
    root->right = sortedArrayToBST(nums, m+1, r);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    int n = nums.size();
    return sortedArrayToBST(nums, 0, n-1);
}

void trimBST(TreeNode* root, TreeNode* &head, int L, int R) {
    if (!root) return;
    TreeNode* right = root->right;
    trimBST(root->left, head, L, R);
    if (root->val >= L && root->val <= R) {
        root->left = head;
        root->right = NULL;
        head = root;
    } else {
        delete root;
    }
    trimBST(right, head, L, R);
}

TreeNode* trimBST(TreeNode* root, int L, int R) {
    TreeNode* head = NULL;
    trimBST(root, head, L, R);
    return head;
}

void printBST(TreeNode* root) {
    if (!root) return;
    printBST(root->left);
    cout << root->val << endl;
    printBST(root->right);
}

int main(void) {
    vector<int> array(2);
    array[0] = 1;
    array[1] = 2;
    TreeNode* root = sortedArrayToBST(array);
    cout << "Before:" << endl;
    printBST(root);
    TreeNode* head = trimBST(root, 2, 4);
    cout << "After:" << endl;
    printBST(head);
    return 0;
}

