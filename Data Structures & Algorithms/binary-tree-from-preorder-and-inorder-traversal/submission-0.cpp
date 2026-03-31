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
    void dfs(TreeNode* root, 
            vector<int>& preorder, vector<int>& inorder, 
            int rootId, int leftMost, int rightMost) {
        for(int i=leftMost; i<=rightMost; i++) {
            if(root->val==inorder[i]) {
                if(i-leftMost>0) {
                    root->left=new TreeNode(preorder[rootId+1]);
                    dfs(root->left, preorder, inorder, rootId+1, leftMost, i-1);
                }
                if(rightMost-i>0) {
                    root->right=new TreeNode(preorder[rootId+i-leftMost+1]);
                    dfs(root->right, preorder, inorder, rootId+i-leftMost+1, i+1, rightMost);
                }
            }
        }
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root=new TreeNode(preorder[0]); 
        dfs(root, preorder, inorder, 0, 0, preorder.size()-1);
        return root;
    }
};
