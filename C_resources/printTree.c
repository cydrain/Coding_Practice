// change an array to a balanced BST Tree
// print a tree level by level
// print the root-to-leaf path for a tree
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int v):val(v),left(NULL),right(NULL){}
};

void printVector(vector<int> &v) {
    if (v.empty()) return;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
}

void printMatrix(vector<vector<int> > &matrix) {
    if (matrix.empty()) return;
    for (int i = 0; i < matrix.size(); i++) {
        printVector(matrix[i]);
    }
}

// convert sorted array to Binary Search Tree
TreeNode* arrayToBST(vector<int> &num, int start, int end) {
    if (start > end) return NULL;
    int mid = start + (end-start)/2;
    TreeNode *root = new TreeNode(num[mid]);
    root->left = arrayToBST(num, start, mid-1);
    root->right = arrayToBST(num, mid+1, end);
    return root;
}

TreeNode* arrayToBST(vector<int> &num) {
    return arrayToBST(num, 0, num.size()-1);
}

// print a tree level by level
vector<vector<int> > levelOrderTraversal(TreeNode *root) {
    queue<TreeNode*> q;
    int l1 = 0, l2 = 0;
    TreeNode *node;
    vector<vector<int> > r;
    vector<int> p;
    if (!root) return r;

    q.push(root);
    l1++;
    while (!q.empty()) {
        node = q.front();
        q.pop();
        l1--;
        p.push_back(node->val);
        if (node->left) {
            q.push(node->left);
            l2++;
        }
        if (node->right) {
            q.push(node->right);
            l2++;
        }
        if (l1 == 0) {
            l1 = l2;
            l2 = 0;
            r.push_back(p);
            p.clear();
        }
    }
    return r;
}

// print all root-to-leaf path of a tree
void printPath(stack<TreeNode*> &path) {
    stack<TreeNode*> tmp;
    TreeNode *node;
    while (!path.empty()) {
        node = path.top();
        path.pop();
        tmp.push(node);
    }
    cout << endl;
    // push all nodes back
    while (!tmp.empty()) {
        node = tmp.top();
        cout << node->val << ' ';
        tmp.pop();
        path.push(node);
    }
}
void pushLeft(TreeNode *node, stack<TreeNode*> &path) {
    while (node) {
        path.push(node);
        node = node->left;
    }
}

void printTreePath(TreeNode *root) {
    if (!root) return;
    stack<TreeNode*> path;
    TreeNode *node, *curr, *parent;
    path.push(root);
    while (!path.empty()) {
        node = path.top();
        // if node is leaf, print this path
        if (!node->left && !node->right) {
            printPath(path);
            path.pop();
            while (!path.empty()) {
                parent = path.top();
                if (node == parent->left && parent->right != NULL) {
                    path.push(parent->right);
                    break;
                }
                else {
                    node = parent;
                    path.pop();
                }
            }
        }
        else if (node->left != NULL) {
            path.push(node->left);
        }
        else if (node->right != NULL) {
            path.push(node->right);
        }
    }
    cout << endl;
}

int main(void) {
    int A[] = {1,2,3,4,5,6,7,8,9};
    vector<int> v(A, A+9);
    TreeNode *root = arrayToBST(v);
    vector<vector<int> > tree_level = levelOrderTraversal(root);
    printMatrix(tree_level);
    printTreePath(root);
    return 0;
}

