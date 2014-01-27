/*
 * Clone a graph. Input is a Node pointer.
 * Return the Node pointer of the cloned graph.
 *
 * A graph is defined below:
 * struct Node {
 *     vector neighbors;
 * }
 */
Node *clone(Node *graph) {
    if (!graph) return NULL;
    unordered_map<Node*, Node*> m;
    queue<Node*> q;
    q.push(graph);

    Node *graphCopy = new Node();
    m[graph] = graphCopy;

    while (!q.empty()) {
        Node *node = q.front();
        q.pop();

        int n = node->neighbors.size();
        for (int i = 0; i < n; i++) {
            Node *neighbor = node->neighbors[i];
            // no copy exits
            if (m.find(neighbor) == m.end()) {
                Node *p = new Node();
                m[node]->neighbors.push_back(p);
                m[neighbor] = p;
                q.push(neighbor);
            }
            // a copy already exists
            else {
                m[node]->neighbors.push_back(m[neighbor]);
            }
        }
    }

    return graphCopy;
}




/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!node) return NULL;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        queue<UndirectedGraphNode*> q;
        UndirectedGraphNode *node_copy = new UndirectedGraphNode(node->label);
        UndirectedGraphNode *n, *n_copy, *p, *p_copy;
        m[node] = node_copy;
        q.push(node);
        while (!q.empty()) {
            n = q.front();
            q.pop();
            n_copy = m[n];
            
            for (int i = 0; i < n->neighbors.size(); i++) {
                p = n->neighbors[i];
                // p has already been cloned
                if (m.find(p) != m.end()) {
                    p_copy = m[p];
                }
                else {
                    p_copy = new UndirectedGraphNode(p->label);
                    m[p] = p_copy;
                    q.push(p);
                }
                n_copy->neighbors.push_back(p_copy);
            }
        }
        return node_copy;
    }
};
