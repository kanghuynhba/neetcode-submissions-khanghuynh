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
private:
    unordered_map<int, Node*> stored;
    unordered_map<int, int> visited;
public:
    void dfs(Node* ans, Node* node) {
        visited[ans->val]=1;
        for(int i=0; i<node->neighbors.size(); i++) {
            int neighborVal=node->neighbors[i]->val;
            if(stored[neighborVal]==NULL) {
                stored[neighborVal]=new Node(neighborVal);
            }
            Node* neighbor=stored[neighborVal];
            if(visited[neighborVal]!=1) {
                ans->neighbors.push_back(neighbor);
                neighbor->neighbors.push_back(ans);
                if(visited[neighborVal]==0) {
                    dfs(neighbor, node->neighbors[i]);
                }
            }
        }
        visited[ans->val]=2;
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) {
            return NULL;
        }
        Node* ans=new Node(node->val); 
        stored[ans->val]=new Node(ans->val);
        dfs(ans, node);
        return ans;
    }
};