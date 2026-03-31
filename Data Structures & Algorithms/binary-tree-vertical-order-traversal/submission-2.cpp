/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    struct Node{
        TreeNode* node;
        int colIndex;
        Node(TreeNode* x, int id) : node(x), colIndex(id) {} 
    };
    int minItv=INT_MAX, maxItv=INT_MIN;
    unordered_map<int, vector<int>> db;
public:
    void bfs(Node* root) {
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node* front=q.front();
            db[front->colIndex].push_back(front->node->val);
            minItv=min(minItv, front->colIndex);
            maxItv=max(maxItv, front->colIndex);
            TreeNode* leftNode=front->node->left;
            TreeNode* rightNode=front->node->right;
            q.pop();
            if(leftNode!=NULL) {
                q.push(new Node(leftNode, front->colIndex-1));
            }
            if(rightNode!=NULL) {
                q.push(new Node(rightNode, front->colIndex+1));
            }
        }
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root==NULL) {
            return {};
        }
        bfs(new Node(root, 0));
        vector<vector<int>> ans(maxItv-minItv+1);
        int k=0;
        for(int i=minItv; i<=maxItv; i++) {
            for(int j=0; j<db[i].size(); j++) {
                ans[k].push_back(db[i][j]);
            }
            k++;
        }    
        return ans;
    }
};
