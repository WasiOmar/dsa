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
 map<Node*,Node*> oldtonew;
        Node* dfs(Node* node){
            if(oldtonew.contains(node)){
                return oldtonew[node];
            }
            Node* copy= new Node(node->val);
            oldtonew[node]= copy;
            for(auto neigh : node->neighbors){
                copy->neighbors.push_back(dfs(neigh));
            }
            return copy;
        }
    Node* cloneGraph(Node* node) {
        return node? dfs(node) : nullptr;
        
    }
};
