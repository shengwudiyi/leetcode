/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode*> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        if(node == NULL) return NULL;
        
        queue<UndirectedGraphNode*> q;
        map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        
        q.push(node);
        
        UndirectedGraphNode* cloneNode = new UndirectedGraphNode(node->label);
        m[node] = cloneNode;
        
        while(!q.empty()) {
            UndirectedGraphNode* n = q.front();
            q.pop();
            
            for(int i=0; i < n->neighbors.size(); i++) {
                UndirectedGraphNode* neighborNode = n->neighbors[i];
                if(m.find(neighborNode) == m.end()) {
                    UndirectedGraphNode* newNode = new UndirectedGraphNode(neighborNode->label);
                    m[neighborNode] = newNode;
                    q.push(neighborNode);
                }
                m[n]->neighbors.push_back(m[neighborNode]);
                
            }
        }
        return cloneNode;
    }
};
