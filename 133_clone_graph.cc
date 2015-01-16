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
        if (!node) return nullptr;
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> m;
        unordered_set<UndirectedGraphNode *> visited;
        unordered_set<UndirectedGraphNode *>::const_iterator it;
        queue<UndirectedGraphNode *> q;
        
        q.push(node);
        visited.insert(node);
        while (!q.empty()) {
            UndirectedGraphNode *front = q.front();
            q.pop();
            UndirectedGraphNode *n = new UndirectedGraphNode(front->label);
            m[front] = n;
            vector<UndirectedGraphNode *> neighbors = front->neighbors;
            int size = neighbors.size();
            for (int i = 0; i < size; ++i) {
                it = visited.find(neighbors[i]);
                if (it == visited.end()) {
                    q.push(neighbors[i]);
                    visited.insert(neighbors[i]);
                }
            }
        }
        
        visited.clear();
        q.push(node);
        visited.insert(node);
        while (!q.empty()) {
            UndirectedGraphNode *front = q.front();
            q.pop();
            vector<UndirectedGraphNode *> neighbors = front->neighbors;
            int size = neighbors.size();
            for (int i = 0; i < size; ++i) {
                m[front]->neighbors.push_back(m[neighbors[i]]);
                it = visited.find(neighbors[i]);
                if (it == visited.end()) {
                    q.push(neighbors[i]);
                    visited.insert(neighbors[i]);
                }
            }
        }
        return m[node];
    }
};
