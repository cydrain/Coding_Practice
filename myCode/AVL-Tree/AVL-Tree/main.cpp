//
//  main.cpp
//  AVL-Tree
//
//  Created by caiyd on 17/12/12.
//  Copyright © 2017年 caiyd. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct AVL_Node {
    int val;
    int height;
    AVL_Node *left;
    AVL_Node *right;
    AVL_Node(int x) : val(x), height(0), left(NULL), right(NULL) {}
};

int getHeight(AVL_Node* node) {
    return (node ? node->height : -1);
}

int findMin(AVL_Node* node) {
    while (node->left) {
        node = node->left;
    }
    return node->val;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                             *
 *          3                                                  *
 *         /       (LL)         2                              *
 *        2       ======>      / \                             *
 *       /                    1   3                            *
 *      1                                                      *
 *                                                             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
AVL_Node* rotateLL(AVL_Node* node) {
    AVL_Node* top = node->left;
    node->left = top->right;
    top->right = node;
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    top->height = max(getHeight(top->left), getHeight(top->right)) + 1;
    cout << "Rotate LL for node " << node->val << endl;
    return top;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                             *
 *      1                                                      *
 *       \          (RR)         2                             *
 *        2        ======>      / \                            *
 *         \                   1   3                           *
 *          3                                                  *
 *                                                             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
AVL_Node* rotateRR(AVL_Node* node) {
    AVL_Node* top = node->right;
    node->right = top->left;
    top->left = node;
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    top->height = max(getHeight(top->left), getHeight(top->right)) + 1;
    cout << "Rotate RR for node " << node->val << endl;
    return top;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                             *
 *        3                     3                              *
 *       /        (RR)         /        (LL)          2        *
 *      1        ======>      2        ======>       / \       *
 *       \                   /                      1   3      *
 *        2                 1                                  *
 *                                                             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
AVL_Node* rotateLR(AVL_Node* node) {
    node->left = rotateRR(node->left);
    return rotateLL(node);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                             *
 *      1                    1                                 *
 *       \         (LL)       \         (RR)          2        *
 *        3       ======>      2       ======>       / \       *
 *       /                      \                   1   3      *
 *      2                        3                             *
 *                                                             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
AVL_Node* rotateRL(AVL_Node* node) {
    node->right = rotateLL(node->right);
    return rotateRR(node);
}

// add node into an AVL-Tree
AVL_Node* addNode(AVL_Node* root, int v) {
    if (root == NULL) {
        root = new AVL_Node(v);
        cout << "Add node " << root->val << endl;
    } else {
        if (v < root->val) {
            root->left = addNode(root->left, v);

            if (getHeight(root->left) - getHeight(root->right) == 2) {
                if (v < root->left->val) {
                    root = rotateLL(root);
                } else {
                    root = rotateLR(root);
                }
            }
        } else if (v > root->val) {
            root->right = addNode(root->right, v);

            if (getHeight(root->right) - getHeight(root->left) == 2) {
                if (v > root->right->val) {
                    root = rotateRR(root);
                } else {
                    root = rotateRL(root);
                }
            }
        } else {
            cout << "Node with value " << v << " already exist!" << endl;
        }
        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    }
    return root;
}

// delete node from an AVL-Tree
AVL_Node* delNode(AVL_Node* root, int v) {
    if (root == NULL) {
        cout << "Node with value " << v << " NOT exist!" << endl;
        return NULL;
    }
    if (v < root->val) {
        root->left = delNode(root->left, v);
        
        // height(right) > height(left)
        if (getHeight(root->right) - getHeight(root->left) == 2) {
            if (root->right->right) {
                root = rotateRR(root);
            } else {
                root = rotateRL(root);
            }
        }
    } else if (v > root->val) {
        root->right = delNode(root->right, v);
        
        // height(left) > height(right)
        if (getHeight(root->left) - getHeight(root->right) == 2) {
            if (root->left->left) {
                root = rotateLL(root);
            } else {
                root = rotateLR(root);
            }
        }
    } else {
        cout << "Del node " << v << endl;
        if (root->left && root->right) {
            root->val = findMin(root->right);
            root->right = delNode(root->right, root->val);
        } else {
            root = (root->left ? root->left : root->right);
            if (root == NULL) return NULL;
        }
    }
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    return root;
}

// pre-order traversal
void printAVL(AVL_Node* root) {
    if (!root) {
        cout << "#";
    } else {
        cout << root->val << "(";
        printAVL(root->left);
        cout << " ";
        printAVL(root->right);
        cout << ")";
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int a[] = {2,1,4,3};
    vector<int> array(a, a+4);
    AVL_Node* root = NULL;
    
    for (int i = 0; i < array.size(); i++) {
        root = addNode(root, array[i]);
    }
    printAVL(root);
    cout << endl;
    
    root = delNode(root, 1);
    printAVL(root);
    cout << endl;
    
    return 0;
}
