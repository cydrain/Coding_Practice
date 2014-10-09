/*
 * Clone Graph
 *
 * Clone an undirected graph. Each node in the graph contains a label and a
 * list of its neighbors.
 *
 * OJ's undirected graph serialization:
 * Nodes are labeled uniquely.
 * We use # as a separator for each node, and , as a separator for node label
 * and each neighbor of the node.
 *
 * As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 *
 * The graph has a total of three nodes, and therefore contains three parts as
 * separated by #.
 *
 * First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 * Second node is labeled as 1. Connect node 1 to node 2.
 * Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming
 * a self-cycle.
 *
 * Visually, the graph looks like the following:
 *
 *        1
 *       / \
 *      /   \
 *     0 --- 2
 *          / \
 *          \_/
 *          
 */
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
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *head) {
        if (!head) return NULL;
        UndirectedGraphNode *headCopy, *node, *nodeCopy, *nb, *nbCopy;
        map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        queue<UndirectedGraphNode*> q;
        int i;
        
        headCopy = new UndirectedGraphNode(head->label);
        m[head] = headCopy;
                
        q.push(head);
        while (!q.empty()) {
            node = q.front();
            q.pop();
            
            nodeCopy = m[node];
            for (i = 0; i < node->neighbors.size(); i++) {
                nb = node->neighbors[i];
                if (m.find(nb) != m.end()) {
                    nbCopy = m[nb];
                    nodeCopy->neighbors.push_back(nbCopy);
                }
                else {
                    nbCopy = new UndirectedGraphNode(nb->label);
                    m[nb] = nbCopy;
                    nodeCopy->neighbors.push_back(nbCopy);
                    q.push(nb);
                }
            }
        }
        return headCopy;
    }
}
