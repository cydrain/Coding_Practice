#include <vector>
#include <string>
using namespace std;

#define INVALID -1000
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& v, int idx) {
    int n = v.size();
    if (idx >= n || v[idx] == INVALID) return NULL;
    TreeNode *root = new TreeNode(v[idx]);
    root->left = buildTree(v, 2*idx+1);
    root->right = buildTree(v, 2*idx+2);
    return root;
}

void printTree(TreeNode* root) {
    if (!root) return;
    printTree(root->left);
    printf("%d ", root->val);
    printTree(root->right);
}

void pathSum(TreeNode *root, int sum, int& result, int level) {
    if (!root) return;
    printf("Debug%d: root->val = %d, sum = %d\n", level, root->val, sum);
    if (root->val == sum) {
        result++;
        printf("Debug%d: find a path\n", level);
    }
    if (root->left) {
        pathSum(root->left, sum-root->val, result, level+1);
        pathSum(root->left, sum, result, level+1);
    }
    if (root->right) {
        pathSum(root->right, sum-root->val, result, level+1);
        pathSum(root->right, sum, result, level+1);
    }
}

int pathSum(TreeNode *root, int sum) {
    int result = 0;
    pathSum(root, sum, result, 0);
    return result;
}

int main(void) {
    int array[] = {10, 5, -3, 3, 2, INVALID, 11, 3, -2, INVALID, 1};
    vector<int> v(array, array+sizeof(array)/sizeof(int));
    TreeNode *root = buildTree(v, 0);
    printTree(root);
    printf("\n");
    printf("%d\n", pathSum(root, 8));
    return 1;
}
