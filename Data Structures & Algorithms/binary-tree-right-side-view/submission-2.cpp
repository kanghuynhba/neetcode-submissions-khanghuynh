
class Solution {
public:
    void addToQueue(queue<pair<TreeNode*, int>>& q, TreeNode* node,
                    int level, vector<int>& ans) {
        if(node) {
            q.push({node, level});
            if(level==ans.size()) {
                ans.push_back(node->val);
            } else {
                ans[level]=node->val;
            }
        }
        
    }
    void bfs(TreeNode* root, vector<int>& ans) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        ans.push_back(root->val);
        TreeNode* curNode;
        int level;
        while(!q.empty()) {
            curNode=q.front().first;
            level=q.front().second+1;
            q.pop();           
            addToQueue(q, curNode->left, level, ans);
            addToQueue(q, curNode->right, level, ans);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;            
        if(root==NULL) {
            return ans;
        }
        bfs(root, ans);
        return ans;
    }
};
