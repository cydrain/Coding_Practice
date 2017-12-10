/*
 * Given a binary tree, find the lowest common ancestor of two given nodes in the tree.
 *
 *         _______3______
 *        /              \
 *     ___5__          ___1__
 *    /      \        /      \
 *    6       2       0       8
 *           / \
 *          7   4
 */
// A Bottom-up Approach (Worst case O(n))
Node *LCA(Node *root, Node *p, Node *q) {
    if (!root) return NULL;
    if (root == p || root == q) return root;
    Node *l_child = LCA(root->left, p, q);
    Node *r_child = LCA(root->right, p, q);
    // if p and q are on both sides
    if (l_child && r_child) return root;
    // either one of p, q is on one side OR
    // p, q is not in L&R subtrees
    return l_child ? l_child : r_child;
}




// A Top-Down Approach (Worst case O(n^2))
// Return #nodes that matches P or Q in the subtree.
int countMatchesPQ(Node *root, Node *p, Node *q) {
    if (!root) return 0;
    int matches = countMatchesPQ(root->left, p, q) + countMatchesPQ(root->right, p, q);
    if (root == p || root == q) {
        return 1 + matches;
    }
    else {
        return matches;
    }
}
 
Node *LCA(Node *root, Node *p, Node *q) {
    if (!root || !p || !q) return NULL;
    if (root == p || root == q) return root;
    int totalMatches = countMatchesPQ(root->left, p, q);
    if (totalMatches == 1) {
        return root;
    }
    else if (totalMatches == 2) {
        return LCA(root->left, p, q);
    }
    else { /* totalMatches == 0 */
        return LCA(root->right, p, q);
    }
}

