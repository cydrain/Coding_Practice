/*
 * Given a binary tree, find the lowest common ancestor of two given nodes in the tree.
 * Each node contains a parent pointer which links to its parent.
 *
 *         _______3______
 *        /              \
 *     ___5__          ___1__
 *    /      \        /      \
 *    6       2       0       8
 *           / \
 *          7   4
 */
int getHeight(Node *p) {
    int height = 0;
    while (p) {
        height++;
        p = p->parent;
    }
    return height;
}

// As root->parent is NULL, we don't need to pass root in.
Node *LCA(Node *p, Node *q) {
    int h1 = getHeight(p);
    int h2 = getHeight(q);
    // swap both node in case p is deeper than q.
    if (h1 > h2) {
        swap(h1, h2);
        swap(p, q);
    }
    int dh = h2 - h1;
    for (int i = 0; i < dh; i++) {
        q = q->parent;
    }
    while (p && q) {
        if (p == q) return p;
        p = p->parent;
        q = q->parent;
    }
    // p and q are not in the same tree
    return NULL;
}

