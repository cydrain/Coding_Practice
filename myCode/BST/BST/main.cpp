//
//  main.cpp
//  BST
//
//  Created by caiyd on 17/12/11.
//  Copyright © 2017年 caiyd. All rights reserved.
//

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

// create a BST from a sorted array
TreeNode* sortedArrayToBST(vector<int>& nums) {
    int n = nums.size();
    return sortedArrayToBST(nums, 0, n-1);
}

// find min value in a BST
int findMin(TreeNode* root) {
    while (root->left) {
        root = root->left;
    }
    return root->val;
}

// add node into a BST
TreeNode* addNode(TreeNode* &root, int v) {
    if (root == NULL) {
        root = new TreeNode(v);
    } else {
        if (v < root->val) {
            root->left = addNode(root->left, v);
        } else if (v > root->val) {
            root->right = addNode(root->right, v);
        } else {
            cout << "Node with value " << v << " already exist!" << endl;
        }
    }
    return root;
}

TreeNode* delNode(TreeNode* &root, int v) {
    if (root == NULL) {
        cout << "Node with value " << v << " NOT exist!" << endl;
        return NULL;
    }
    if (v < root->val) {
        root->left = delNode(root->left, v);
    } else if (v > root->val) {
        root->right = delNode(root->right, v);
    } else {
        if (root->left && root->right) {
            root->val = findMin(root->right);
            root->right = delNode(root->right, root->val);
        } else {
            root = (root->left ? root->left : root->right);
        }
    }
    return root;
}

void searchBST(TreeNode* root, vector<int> &res, int L, int R) {
    if (!root) return;
    searchBST(root->left, res, L, R);
    if (root->val >= L && root->val <= R) {
        res.push_back(root->val);
    }
    searchBST(root->right, res, L, R);
}

vector<int> searchBST(TreeNode* root, int L, int R) {
    vector<int> res;
    searchBST(root, res, L, R);
    return res;
}

// pre-order traversal
void printBST(TreeNode* root) {
    if (!root) {
        cout << "#";
    } else {
        cout << root->val << "(";
        printBST(root->left);
        cout << " ";
        printBST(root->right);
        cout << ")";
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int a[6] = {2,3,1,4,5,6};
    vector<int> array(a, a+6);
    TreeNode* root = NULL;

    for (int i = 0; i < array.size(); i++) {
        root = addNode(root, array[i]);
    }
    root = delNode(root, 5);
    printBST(root);
    cout << endl;
    
    vector<int> res = searchBST(root, 2, 7);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << ' ';
    }
    cout << endl;
    
    return 0;
}

