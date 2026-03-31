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
   TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val==p->val || root->val==q->val) {
            return root;
        }
        int minVal=min(root->val, min(q->val, p->val));
        int maxVal=max(root->val, max(q->val, p->val));
        if(root->val==minVal) {
            return lowestCommonAncestor(root->right, p, q);
        } else if(root->val==maxVal) {
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};
