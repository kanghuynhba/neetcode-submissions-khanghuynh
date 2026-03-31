
class Solution {
public:
    void bfs(TreeNode* root, vector<int>& ans) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        ans.push_back(root->val);
        while(!q.empty()) {
            TreeNode* s=q.front().first;
            int level=q.front().second+1;
            q.pop();           
            if(s->left) {
                q.push({s->left, level});
                if(level==ans.size()) {
                    ans.push_back(s->left->val);
                } else {
                    ans[level]=s->left->val;
                }
            }
            if(s->right) {
                q.push({s->right, level});
                if(level==ans.size()) {
                    ans.push_back(s->right->val);
                } else {
                    ans[level]=s->right->val;
                }
            }
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