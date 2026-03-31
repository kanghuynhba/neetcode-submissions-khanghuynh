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
    void addAugment(TreeNode* root, unordered_map<int, pair<int, int>>& augment, bool& flag) {
        if(root==NULL) {
            return;
        }
        addAugment(root->left, augment, flag);
        addAugment(root->right, augment, flag);
        if(!flag) {
            return;
        }
        augment[root->val]={root->val, root->val};
        if(root->left) {
            if(augment[root->val].second<=augment[root->left->val].second) {
                flag=false;
                return;
            }
            augment[root->val].first=augment[root->left->val].first;
        }  
        if(root->right) {
            if(augment[root->val].second>=augment[root->right->val].first) {
                flag=false;
                return;
            }
            augment[root->val].second=augment[root->right->val].second;
        }
    }
    bool isValidBST(TreeNode* root) {
        unordered_map<int, pair<int, int>> augment;
        bool flag=true;
        addAugment(root, augment, flag);
        return flag;
    }
};

