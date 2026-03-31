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
public:
    void preorderTraversal(TreeNode* root, vector<vector<int>>& ans, int level) {
        if(root==NULL) {
            return;
        } 
        if(ans.size()==level) {
            ans.push_back({});
        }       
        ans[level].push_back(root->val);
        preorderTraversal(root->left, ans, level+1);
        preorderTraversal(root->right, ans, level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int level=0;
        preorderTraversal(root, ans, level);        
        return ans;
    }
};
