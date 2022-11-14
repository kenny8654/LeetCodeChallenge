/**
Runtime: 3 ms, Beats: 98.73%
Memory: 9.2 MB, Beats: 10%
**/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        Node* pCurr;
        unordered_map<Node*, Node*> map; 
        unordered_set<Node*> s;
        travalOrigin(node, map);
        travalCloned(map[node], s, map);
        return map[node];
    }

    void travalOrigin(Node* node, unordered_map<Node*, Node*>& map){
        if(node == nullptr) return;
        if(map.find(node) != map.end()) return;

        Node* tmp = new Node(node->val, node->neighbors);
        map[node] = tmp;
        for(auto& neighbor:node->neighbors){
            travalOrigin(neighbor, map);
        }
    }

    void travalCloned(Node* node, unordered_set<Node*>& s, unordered_map<Node*, Node*>& map){
        if(node == nullptr) return;
        if(s.find(node) != s.end()) return;

        s.insert(node);
        for(auto& neighbor:node->neighbors)
            neighbor = map[neighbor];
        for(auto& neighbor:node->neighbors)
            travalCloned(neighbor, s, map);    
    }

};
