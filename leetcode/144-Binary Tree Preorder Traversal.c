// Binary Tree Preorder Traversal
//
// Given a binary tree, return the preorder traversal of its nodes' values.
// For example:
// Given binary tree {1,#,2,3},
//
//    1
//     \
//      2
//     /
//    3
//
// return [1,2,3]. 
//

vector<int> preorderTraversal(TreeNode *root) {
    stack<TreeNode*> s;
    vector<int> r;
    TreeNode *node;
    if (!root) return r;
    
    s.push(root);
    while (!s.empty()) {
        node = s.top();
        s.pop();
        r.push_back(node->val);
        if (node->right) s.push(node->right);
        if (node->left) s.push(node->left);
    }
    
    return r;
}

